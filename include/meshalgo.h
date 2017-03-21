/*************************************************************************
 * Copyright (c) 2014 Zhang Dongdong
 * All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**************************************************************************/
#ifndef MESHALGO_H
#define MESHALGO_H
#include "trianglemesh.h"

// Smooth the mesh geometry
extern void smooth_mesh(TriangleMesh *themesh, float sigma);

// Bilateral smoothing
extern void bilateral_smooth_mesh(TriangleMesh *themesh, float sigma1, float sigma2);

// Diffuse an arbitrary per-vertex vector (or scalar) field
template <class T>
extern void diffuse_vector(TriangleMesh *themesh, std::vector<T> &field, float sigma);

// Diffuse the normals across the mesh
extern void diffuse_normals(TriangleMesh *themesh, float sigma);

extern void zdd_diffuse_curv(TriangleMesh *themesh, float sigma);

// Diffuse the curvatures across the mesh
extern void diffuse_curv(TriangleMesh *themesh, float sigma);

// Diffuse the curvature derivatives across the mesh
extern void diffuse_dcurv(TriangleMesh *themesh, float sigma);

// Given a curvature tensor, find principal directions and curvatures
extern void diagonalize_curv(const vec &old_u, const vec &old_v,
                             float ku, float kuv, float kv,
                             const vec &new_norm,
                             vec &pdir1, vec &pdir2, float &k1, float &k2);

// Reproject a curvature tensor from the basis spanned by old_u and old_v
// (which are assumed to be unit-length and perpendicular) to the
// new_u, new_v basis.
extern void proj_curv(const vec &old_u, const vec &old_v,
                      float old_ku, float old_kuv, float old_kv,
                      const vec &new_u, const vec &new_v,
                      float &new_ku, float &new_kuv, float &new_kv);

// Like the above, but for dcurv
extern void proj_dcurv(const vec &old_u, const vec &old_v,
                       const Vec<4> old_dcurv,
                       const vec &new_u, const vec &new_v,
                       Vec<4> &new_dcurv);


#endif // MESHALGO_H
