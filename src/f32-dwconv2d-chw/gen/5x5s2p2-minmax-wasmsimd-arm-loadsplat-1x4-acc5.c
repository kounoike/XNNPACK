// Auto-generated file. Do not edit!
//   Template: src/f32-dwconv2d-chw/5x5s2p2-wasmsimd-loadsplat.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <wasm_simd128.h>

#include <xnnpack/dwconv.h>
#include <xnnpack/math.h>



void xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_loadsplat_1x4_acc5(

    size_t input_height,
    size_t input_width,
    const float* input,
    const float* weights,
    const float* zero,
    float* output,
    uint32_t padding_top,
    const union xnn_f32_chw_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(input_height != 0);
  assert(input_width != 0);
  assert(input_width % sizeof(float) == 0);
  assert(padding_top >= 1);
  assert(padding_top <= 2);

  const v128_t vmask_even = wasm_v128_load(params->scalar.mask_even);
  const v128_t vmask_odd  = wasm_v128_load(params->scalar.mask_odd);
  const v128_t vmax = wasm_v128_load32_splat(&params->scalar.max);
  const v128_t vmin = wasm_v128_load32_splat(&params->scalar.min);

  const v128_t vbias = wasm_v128_load32_splat(weights);
  const v128_t vk00 = wasm_v128_load32_splat(weights + 1);
  const v128_t vk01 = wasm_v128_load32_splat(weights + 2);
  const v128_t vk02 = wasm_v128_load32_splat(weights + 3);
  const v128_t vk03 = wasm_v128_load32_splat(weights + 4);
  const v128_t vk04 = wasm_v128_load32_splat(weights + 5);
  const v128_t vk10 = wasm_v128_load32_splat(weights + 6);
  const v128_t vk11 = wasm_v128_load32_splat(weights + 7);
  const v128_t vk12 = wasm_v128_load32_splat(weights + 8);
  const v128_t vk13 = wasm_v128_load32_splat(weights + 9);
  const v128_t vk14 = wasm_v128_load32_splat(weights + 10);
  const v128_t vk20 = wasm_v128_load32_splat(weights + 11);
  const v128_t vk21 = wasm_v128_load32_splat(weights + 12);
  const v128_t vk22 = wasm_v128_load32_splat(weights + 13);
  const v128_t vk23 = wasm_v128_load32_splat(weights + 14);
  const v128_t vk24 = wasm_v128_load32_splat(weights + 15);
  const v128_t vk30 = wasm_v128_load32_splat(weights + 16);
  const v128_t vk31 = wasm_v128_load32_splat(weights + 17);
  const v128_t vk32 = wasm_v128_load32_splat(weights + 18);
  const v128_t vk33 = wasm_v128_load32_splat(weights + 19);
  const v128_t vk34 = wasm_v128_load32_splat(weights + 20);
  const v128_t vk40 = wasm_v128_load32_splat(weights + 21);
  const v128_t vk41 = wasm_v128_load32_splat(weights + 22);
  const v128_t vk42 = wasm_v128_load32_splat(weights + 23);
  const v128_t vk43 = wasm_v128_load32_splat(weights + 24);
  const v128_t vk44 = wasm_v128_load32_splat(weights + 25);

  const v128_t vzero = wasm_f64x2_splat(0.0);

  const uint32_t padding_top_less_1 = padding_top - 1;
  const size_t input_decrement = round_up_po2(input_width, 8 * sizeof(float));

  const float* i0 = zero;
  const float* i1 = (const float*) ((uintptr_t) input - ((-padding_top_less_1) & input_width));
  const float* i2 = (const float*) ((uintptr_t) i1 + input_width);
  if XNN_UNPREDICTABLE(padding_top_less_1 != 0) {
    i1 = zero;
  }
  const float* i3 = (const float*) ((uintptr_t) i2 + input_width);
  const float* i4 = (const float*) ((uintptr_t) i3 + input_width);


  float* o0 = output;

  size_t padded_input_height = input_height + (padding_top_less_1 + 1) + 2 /* padding bottom */;
  size_t output_height = (padded_input_height - 5 /* kernel size */ + 2 /* subsampling */) / 2;
  do {
    if XNN_UNPREDICTABLE(padded_input_height < 6) {
      i3 = zero;
    }
    if XNN_UNPREDICTABLE(padded_input_height < 7) {
      i4 = zero;
    }

    v128_t vi0x0246 = vzero;
    v128_t vi1x0246 = vzero;
    v128_t vi2x0246 = vzero;
    v128_t vi3x0246 = vzero;
    v128_t vi4x0246 = vzero;

    v128_t vi0x1357 = vzero;
    v128_t vi1x1357 = vzero;
    v128_t vi2x1357 = vzero;
    v128_t vi3x1357 = vzero;
    v128_t vi4x1357 = vzero;

    const v128_t vi0x89AB = wasm_v128_load(i0);
    const v128_t vi0xCDEF = wasm_v128_load(i0 + 4);
    i0 += 8;
    const v128_t vi1x89AB = wasm_v128_load(i1);
    const v128_t vi1xCDEF = wasm_v128_load(i1 + 4);
    i1 += 8;
    const v128_t vi2x89AB = wasm_v128_load(i2);
    const v128_t vi2xCDEF = wasm_v128_load(i2 + 4);
    i2 += 8;
    const v128_t vi3x89AB = wasm_v128_load(i3);
    const v128_t vi3xCDEF = wasm_v128_load(i3 + 4);
    i3 += 8;
    const v128_t vi4x89AB = wasm_v128_load(i4);
    const v128_t vi4xCDEF = wasm_v128_load(i4 + 4);
    i4 += 8;

    v128_t vi0x8ACE = wasm_v32x4_shuffle(vi0x89AB, vi0xCDEF, 0, 2, 4, 6);
    v128_t vi0x9BDF = wasm_v32x4_shuffle(vi0x89AB, vi0xCDEF, 1, 3, 5, 7);
    v128_t vi1x8ACE = wasm_v32x4_shuffle(vi1x89AB, vi1xCDEF, 0, 2, 4, 6);
    v128_t vi1x9BDF = wasm_v32x4_shuffle(vi1x89AB, vi1xCDEF, 1, 3, 5, 7);
    v128_t vi2x8ACE = wasm_v32x4_shuffle(vi2x89AB, vi2xCDEF, 0, 2, 4, 6);
    v128_t vi2x9BDF = wasm_v32x4_shuffle(vi2x89AB, vi2xCDEF, 1, 3, 5, 7);
    v128_t vi3x8ACE = wasm_v32x4_shuffle(vi3x89AB, vi3xCDEF, 0, 2, 4, 6);
    v128_t vi3x9BDF = wasm_v32x4_shuffle(vi3x89AB, vi3xCDEF, 1, 3, 5, 7);
    v128_t vi4x8ACE = wasm_v32x4_shuffle(vi4x89AB, vi4xCDEF, 0, 2, 4, 6);
    v128_t vi4x9BDF = wasm_v32x4_shuffle(vi4x89AB, vi4xCDEF, 1, 3, 5, 7);

    size_t w = input_width;
    for (; w > 8 * sizeof(float); w -= 8 * sizeof(float)) {
      v128_t vo0p0 = vbias;

      v128_t vo0p1 = wasm_f32x4_mul(vi0x8ACE, vk02);

      v128_t vo0p2 = wasm_f32x4_mul(vi1x8ACE, vk12);

      v128_t vo0p3 = wasm_f32x4_mul(vi2x8ACE, vk22);

      v128_t vo0p4 = wasm_f32x4_mul(vi3x8ACE, vk32);

      vo0p1 = wasm_f32x4_add(vo0p1, wasm_f32x4_mul(vi4x8ACE, vk42));

      vo0p2 = wasm_f32x4_add(vo0p2, wasm_f32x4_mul(vi0x9BDF, vk03));

      vo0p3 = wasm_f32x4_add(vo0p3, wasm_f32x4_mul(vi1x9BDF, vk13));

      vo0p4 = wasm_f32x4_add(vo0p4, wasm_f32x4_mul(vi2x9BDF, vk23));

      vo0p0 = wasm_f32x4_add(vo0p0, wasm_f32x4_mul(vi3x9BDF, vk33));

      vo0p1 = wasm_f32x4_add(vo0p1, wasm_f32x4_mul(vi4x9BDF, vk43));

      const v128_t vi0x68AC = wasm_v32x4_shuffle(vi0x0246, vi0x8ACE, 3, 4, 5, 6);
      vi0x0246 = vi0x8ACE;
      const v128_t vi1x68AC = wasm_v32x4_shuffle(vi1x0246, vi1x8ACE, 3, 4, 5, 6);
      vi1x0246 = vi1x8ACE;
      const v128_t vi2x68AC = wasm_v32x4_shuffle(vi2x0246, vi2x8ACE, 3, 4, 5, 6);
      vi2x0246 = vi2x8ACE;
      const v128_t vi3x68AC = wasm_v32x4_shuffle(vi3x0246, vi3x8ACE, 3, 4, 5, 6);
      vi3x0246 = vi3x8ACE;
      const v128_t vi4x68AC = wasm_v32x4_shuffle(vi4x0246, vi4x8ACE, 3, 4, 5, 6);
      vi4x0246 = vi4x8ACE;

      vo0p2 = wasm_f32x4_add(vo0p2, wasm_f32x4_mul(vi0x68AC, vk00));

      vo0p3 = wasm_f32x4_add(vo0p3, wasm_f32x4_mul(vi1x68AC, vk10));

      vo0p4 = wasm_f32x4_add(vo0p4, wasm_f32x4_mul(vi2x68AC, vk20));

      vo0p0 = wasm_f32x4_add(vo0p0, wasm_f32x4_mul(vi3x68AC, vk30));

      vo0p1 = wasm_f32x4_add(vo0p1, wasm_f32x4_mul(vi4x68AC, vk40));

      const v128_t vi0x79BD = wasm_v32x4_shuffle(vi0x1357, vi0x9BDF, 3, 4, 5, 6);
      vi0x1357 = vi0x9BDF;
      const v128_t vi1x79BD = wasm_v32x4_shuffle(vi1x1357, vi1x9BDF, 3, 4, 5, 6);
      vi1x1357 = vi1x9BDF;
      const v128_t vi2x79BD = wasm_v32x4_shuffle(vi2x1357, vi2x9BDF, 3, 4, 5, 6);
      vi2x1357 = vi2x9BDF;
      const v128_t vi3x79BD = wasm_v32x4_shuffle(vi3x1357, vi3x9BDF, 3, 4, 5, 6);
      vi3x1357 = vi3x9BDF;
      const v128_t vi4x79BD = wasm_v32x4_shuffle(vi4x1357, vi4x9BDF, 3, 4, 5, 6);
      vi4x1357 = vi4x9BDF;

      const v128_t vi0xGHIJ = wasm_v128_load(i0);
      const v128_t vi0xKLMN = wasm_v128_load(i0 + 4);
      i0 += 8;
      const v128_t vi1xGHIJ = wasm_v128_load(i1);
      const v128_t vi1xKLMN = wasm_v128_load(i1 + 4);
      i1 += 8;
      const v128_t vi2xGHIJ = wasm_v128_load(i2);
      const v128_t vi2xKLMN = wasm_v128_load(i2 + 4);
      i2 += 8;
      const v128_t vi3xGHIJ = wasm_v128_load(i3);
      const v128_t vi3xKLMN = wasm_v128_load(i3 + 4);
      i3 += 8;
      const v128_t vi4xGHIJ = wasm_v128_load(i4);
      const v128_t vi4xKLMN = wasm_v128_load(i4 + 4);
      i4 += 8;

      const v128_t vi0xGIKM = wasm_v32x4_shuffle(vi0xGHIJ, vi0xKLMN, 0, 2, 4, 6);
      const v128_t vi0xHJLN = wasm_v32x4_shuffle(vi0xGHIJ, vi0xKLMN, 1, 3, 5, 7);
      const v128_t vi1xGIKM = wasm_v32x4_shuffle(vi1xGHIJ, vi1xKLMN, 0, 2, 4, 6);
      const v128_t vi1xHJLN = wasm_v32x4_shuffle(vi1xGHIJ, vi1xKLMN, 1, 3, 5, 7);
      const v128_t vi2xGIKM = wasm_v32x4_shuffle(vi2xGHIJ, vi2xKLMN, 0, 2, 4, 6);
      const v128_t vi2xHJLN = wasm_v32x4_shuffle(vi2xGHIJ, vi2xKLMN, 1, 3, 5, 7);
      const v128_t vi3xGIKM = wasm_v32x4_shuffle(vi3xGHIJ, vi3xKLMN, 0, 2, 4, 6);
      const v128_t vi3xHJLN = wasm_v32x4_shuffle(vi3xGHIJ, vi3xKLMN, 1, 3, 5, 7);
      const v128_t vi4xGIKM = wasm_v32x4_shuffle(vi4xGHIJ, vi4xKLMN, 0, 2, 4, 6);
      const v128_t vi4xHJLN = wasm_v32x4_shuffle(vi4xGHIJ, vi4xKLMN, 1, 3, 5, 7);

      vo0p2 = wasm_f32x4_add(vo0p2, wasm_f32x4_mul(vi0x79BD, vk01));

      vo0p3 = wasm_f32x4_add(vo0p3, wasm_f32x4_mul(vi1x79BD, vk11));

      vo0p4 = wasm_f32x4_add(vo0p4, wasm_f32x4_mul(vi2x79BD, vk21));

      vo0p0 = wasm_f32x4_add(vo0p0, wasm_f32x4_mul(vi3x79BD, vk31));

      vo0p1 = wasm_f32x4_add(vo0p1, wasm_f32x4_mul(vi4x79BD, vk41));

      const v128_t vi0xACEG = wasm_v32x4_shuffle(vi0x8ACE, vi0xGIKM, 1, 2, 3, 4);
      vi0x8ACE = vi0xGIKM;
      vi0x9BDF = vi0xHJLN;
      const v128_t vi1xACEG = wasm_v32x4_shuffle(vi1x8ACE, vi1xGIKM, 1, 2, 3, 4);
      vi1x8ACE = vi1xGIKM;
      vi1x9BDF = vi1xHJLN;
      const v128_t vi2xACEG = wasm_v32x4_shuffle(vi2x8ACE, vi2xGIKM, 1, 2, 3, 4);
      vi2x8ACE = vi2xGIKM;
      vi2x9BDF = vi2xHJLN;
      const v128_t vi3xACEG = wasm_v32x4_shuffle(vi3x8ACE, vi3xGIKM, 1, 2, 3, 4);
      vi3x8ACE = vi3xGIKM;
      vi3x9BDF = vi3xHJLN;
      const v128_t vi4xACEG = wasm_v32x4_shuffle(vi4x8ACE, vi4xGIKM, 1, 2, 3, 4);
      vi4x8ACE = vi4xGIKM;
      vi4x9BDF = vi4xHJLN;

      vo0p2 = wasm_f32x4_add(vo0p2, wasm_f32x4_mul(vi0xACEG, vk04));

      vo0p3 = wasm_f32x4_add(vo0p3, wasm_f32x4_mul(vi1xACEG, vk14));

      vo0p4 = wasm_f32x4_add(vo0p4, wasm_f32x4_mul(vi2xACEG, vk24));

      vo0p0 = wasm_f32x4_add(vo0p0, wasm_f32x4_mul(vi3xACEG, vk34));

      vo0p1 = wasm_f32x4_add(vo0p1, wasm_f32x4_mul(vi4xACEG, vk44));

      vo0p0 = wasm_f32x4_add(vo0p0, vo0p1);
      vo0p2 = wasm_f32x4_add(vo0p2, vo0p3);
      vo0p0 = wasm_f32x4_add(vo0p0, vo0p2);
      vo0p0 = wasm_f32x4_add(vo0p0, vo0p4);

      v128_t vo0 = wasm_f32x4_max(vo0p0, vmin);
      vo0 = wasm_f32x4_min(vo0, vmax);

      wasm_v128_store(o0, vo0); o0 += 4;
    }
    // Last block has 1-8 pixels to process.
    assert(w <= 8 * sizeof(float));
    assert(w >= 1 * sizeof(float));
    {
      v128_t vo0p0 = vbias;

      vi0x8ACE = wasm_v128_and(vmask_even, vi0x8ACE);
      vi1x8ACE = wasm_v128_and(vmask_even, vi1x8ACE);
      vi2x8ACE = wasm_v128_and(vmask_even, vi2x8ACE);
      vi3x8ACE = wasm_v128_and(vmask_even, vi3x8ACE);
      vi4x8ACE = wasm_v128_and(vmask_even, vi4x8ACE);

      vi0x9BDF = wasm_v128_and(vmask_odd, vi0x9BDF);
      vi1x9BDF = wasm_v128_and(vmask_odd, vi1x9BDF);
      vi2x9BDF = wasm_v128_and(vmask_odd, vi2x9BDF);
      vi3x9BDF = wasm_v128_and(vmask_odd, vi3x9BDF);
      vi4x9BDF = wasm_v128_and(vmask_odd, vi4x9BDF);

      v128_t vo0p1 = wasm_f32x4_mul(vi0x8ACE, vk02);

      v128_t vo0p2 = wasm_f32x4_mul(vi1x8ACE, vk12);

      v128_t vo0p3 = wasm_f32x4_mul(vi2x8ACE, vk22);

      v128_t vo0p4 = wasm_f32x4_mul(vi3x8ACE, vk32);

      vo0p1 = wasm_f32x4_add(vo0p1, wasm_f32x4_mul(vi4x8ACE, vk42));

      vo0p2 = wasm_f32x4_add(vo0p2, wasm_f32x4_mul(vi0x9BDF, vk03));

      vo0p3 = wasm_f32x4_add(vo0p3, wasm_f32x4_mul(vi1x9BDF, vk13));

      vo0p4 = wasm_f32x4_add(vo0p4, wasm_f32x4_mul(vi2x9BDF, vk23));

      vo0p0 = wasm_f32x4_add(vo0p0, wasm_f32x4_mul(vi3x9BDF, vk33));

      vo0p1 = wasm_f32x4_add(vo0p1, wasm_f32x4_mul(vi4x9BDF, vk43));

      const v128_t vi0x68AC = wasm_v32x4_shuffle(vi0x0246, vi0x8ACE, 3, 4, 5, 6);
      const v128_t vi1x68AC = wasm_v32x4_shuffle(vi1x0246, vi1x8ACE, 3, 4, 5, 6);
      const v128_t vi2x68AC = wasm_v32x4_shuffle(vi2x0246, vi2x8ACE, 3, 4, 5, 6);
      const v128_t vi3x68AC = wasm_v32x4_shuffle(vi3x0246, vi3x8ACE, 3, 4, 5, 6);
      const v128_t vi4x68AC = wasm_v32x4_shuffle(vi4x0246, vi4x8ACE, 3, 4, 5, 6);

      vo0p2 = wasm_f32x4_add(vo0p2, wasm_f32x4_mul(vi0x68AC, vk00));

      vo0p3 = wasm_f32x4_add(vo0p3, wasm_f32x4_mul(vi1x68AC, vk10));

      vo0p4 = wasm_f32x4_add(vo0p4, wasm_f32x4_mul(vi2x68AC, vk20));

      vo0p0 = wasm_f32x4_add(vo0p0, wasm_f32x4_mul(vi3x68AC, vk30));

      vo0p1 = wasm_f32x4_add(vo0p1, wasm_f32x4_mul(vi4x68AC, vk40));

      const v128_t vi0x79BD = wasm_v32x4_shuffle(vi0x1357, vi0x9BDF, 3, 4, 5, 6);
      const v128_t vi1x79BD = wasm_v32x4_shuffle(vi1x1357, vi1x9BDF, 3, 4, 5, 6);
      const v128_t vi2x79BD = wasm_v32x4_shuffle(vi2x1357, vi2x9BDF, 3, 4, 5, 6);
      const v128_t vi3x79BD = wasm_v32x4_shuffle(vi3x1357, vi3x9BDF, 3, 4, 5, 6);
      const v128_t vi4x79BD = wasm_v32x4_shuffle(vi4x1357, vi4x9BDF, 3, 4, 5, 6);

      vo0p2 = wasm_f32x4_add(vo0p2, wasm_f32x4_mul(vi0x79BD, vk01));

      vo0p3 = wasm_f32x4_add(vo0p3, wasm_f32x4_mul(vi1x79BD, vk11));

      vo0p4 = wasm_f32x4_add(vo0p4, wasm_f32x4_mul(vi2x79BD, vk21));

      vo0p0 = wasm_f32x4_add(vo0p0, wasm_f32x4_mul(vi3x79BD, vk31));

      vo0p1 = wasm_f32x4_add(vo0p1, wasm_f32x4_mul(vi4x79BD, vk41));

      const v128_t vi0xACEG = wasm_v32x4_shuffle(vi0x8ACE, vzero, 1, 2, 3, 4);
      const v128_t vi1xACEG = wasm_v32x4_shuffle(vi1x8ACE, vzero, 1, 2, 3, 4);
      const v128_t vi2xACEG = wasm_v32x4_shuffle(vi2x8ACE, vzero, 1, 2, 3, 4);
      const v128_t vi3xACEG = wasm_v32x4_shuffle(vi3x8ACE, vzero, 1, 2, 3, 4);
      const v128_t vi4xACEG = wasm_v32x4_shuffle(vi4x8ACE, vzero, 1, 2, 3, 4);

      vo0p2 = wasm_f32x4_add(vo0p2, wasm_f32x4_mul(vi0xACEG, vk04));

      vo0p3 = wasm_f32x4_add(vo0p3, wasm_f32x4_mul(vi1xACEG, vk14));

      vo0p4 = wasm_f32x4_add(vo0p4, wasm_f32x4_mul(vi2xACEG, vk24));

      vo0p0 = wasm_f32x4_add(vo0p0, wasm_f32x4_mul(vi3xACEG, vk34));

      vo0p1 = wasm_f32x4_add(vo0p1, wasm_f32x4_mul(vi4xACEG, vk44));

      vo0p0 = wasm_f32x4_add(vo0p0, vo0p1);
      vo0p2 = wasm_f32x4_add(vo0p2, vo0p3);
      vo0p0 = wasm_f32x4_add(vo0p0, vo0p2);
      vo0p0 = wasm_f32x4_add(vo0p0, vo0p4);

      v128_t vo0 = wasm_f32x4_max(vo0p0, vmin);
      vo0 = wasm_f32x4_min(vo0, vmax);

      size_t w_tmp = (w + 1 * sizeof(float)) / (2 * sizeof(float));
      if XNN_LIKELY(w_tmp >= 4) {
        wasm_v128_store(o0, vo0); o0 += 4;
      } else {
        if (w_tmp & 2) {
          *((double*) o0) = wasm_f64x2_extract_lane(vo0, 0); o0 += 2;

          vo0 = wasm_v32x4_shuffle(vo0, vo0, 2, 3, 0, 1);
        }
        if (w_tmp & 1) {
          *o0 = wasm_f32x4_extract_lane(vo0, 0); o0 += 1;
        }
      }
    }

    i0 = (const float*) ((uintptr_t) i2 - input_decrement);
    i1 = (const float*) ((uintptr_t) i3 - input_decrement);
    i2 = (const float*) ((uintptr_t) i4 - input_decrement);
    i3 = (const float*) ((uintptr_t) i2 + input_width);
    i4 = (const float*) ((uintptr_t) i3 + input_width);


    output_height -= 1;
    padded_input_height -= 2;
  } while (output_height != 0);
}
