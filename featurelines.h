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
#ifndef FEATURELINES_H
#define FEATURELINES_H

#include <QString>

#include "trianglemesh.h"

class Line {
public:
    point p0;
    point p1;

    Line() {}
    Line(const point &_p0, const point &_p1)
            { p0 = _p0; p1 = _p1; }
};

class LineIndex {
public:
    int p0;
    int p1;

    LineIndex(){}
    LineIndex(const int &_p0, const int &_p1)
    { p0 = _p0; p1 = _p1; }
};

class FeatureLines
{
public:
    FeatureLines();
public:
    TriangleMesh::BSphere sphere; //所在包围球

    //包含特征线的三角形_使用原模型的顶点索引存储
    std::vector<TriangleMesh::Face> faces;

    //包含特征线的顶点__ 仅在合并后使用
    std::vector<point> vertices;
    std::vector<TriangleMesh::Face> v_faces; //合并后新的索引三角形

    //特征线存储
    std::vector<Line> lines;

    //特征线的顶点 索引线存储
    std::vector<point> fl_vertices;
    std::vector<LineIndex> fl_lines;


    void clear()
    {
        faces.clear();
        vertices.clear();
        lines.clear();
        v_faces.clear();

        fl_vertices.clear();
        fl_lines.clear();
    }

    void readLinesFromFile(const QString& fileName);

    bool writeLinesToFile(const QString& fileName);
    bool writeFacesToObj(const QString& fileName, const TriangleMesh *triMesh);

    void drawLines();
    void drawFaces(const TriangleMesh *triMesh, const vec4 &color);

};

#endif // FEATURELINES_H
