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
#include "featurelines.h"
#include <QFile>
#include <QTextStream>

#include <set>

#include <qgl.h>

FeatureLines::FeatureLines()
{
}

void FeatureLines::drawLines()
{
    if(!lines.size())
        return;
    glLineWidth(2);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
    glBegin(GL_LINES);
    for(int i = 0; i < lines.size(); i++)
    {
        glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
        glVertex3fv(lines[i].p0);
        glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
        glVertex3fv(lines[i].p1);
    }

    glEnd();
}

void FeatureLines::drawFaces(const TriangleMesh *triMesh, const vec4 &color)
{
    if(!triMesh || !faces.size())
        return;

    glLineWidth(1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor4fv(color);
    glBegin(GL_TRIANGLES);
    for(int i = 0; i < faces.size(); i++)
    {
        glVertex3fv(triMesh->vertices[faces[i][0]]);
        glVertex3fv(triMesh->vertices[faces[i][1]]);
        glVertex3fv(triMesh->vertices[faces[i][2]]);
    }
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

void FeatureLines::readLinesFromFile(const QString &fileName)
{
//    QFile *file = new QFile(fileName);

//    if(file->open(QFile::ReadOnly))
//    {
//        QTextStream in(file);
//        QString line;
//     do {
//         line = stream.readLine();
//     } while (!line.isNull());
//    }
}

bool FeatureLines::writeLinesToFile(const QString &fileName)
{
    fl_vertices.clear();
    fl_lines.clear();

    for(int i = 0; i < lines.size(); i++)
    {
        int index1 = -1, index2 = -1; //线的顶点索引从1开始

        //倒序，更快的排除重复点
        int j = 0;

        if(i == 0)
        {
            index1 = 0;
            fl_vertices.push_back(lines[i].p0);
        }
        else
        {
            for(j = fl_vertices.size() -1; j >-1; j--)
            {
                if(fl_vertices[j] == lines[i].p0)
                    break;
            }

            if(j == -1)
            {
                index1 = fl_vertices.size();
                fl_vertices.push_back(lines[i].p0);
            }
            else
            {
                index1 = j;
            }
        }

        for(j = fl_vertices.size() -1; j > -1; j--)
        {
            if(fl_vertices[j] == lines[i].p1)
                break;
        }

        if(j == -1)
        {
            index2 = fl_vertices.size();
            fl_vertices.push_back(lines[i].p1);
        }
        else
        {
            index2 = j;
        }

        if(index1 != index2)
            fl_lines.push_back(LineIndex(index1, index2));
    }

    QFile *file = new QFile(fileName);

    if(file->open(QFile::WriteOnly))
    {
        QTextStream out(file);

        out << "s " << sphere.center[0]<< " " << sphere.center[1] <<" " << sphere.center[2]<< " " <<sphere.r << "\r\n";

//        for(int i = 0; i < lines.size(); i++)
//        {
//            out << "v " <<lines[i].p0[0] << " " << lines[i].p0[1] <<" " << lines[i].p0[2]<< "\r\n";
//            out << "v " <<lines[i].p1[0] << " " << lines[i].p1[1] <<" " << lines[i].p1[2]<< "\r\n";
//        }

        for(int i = 0; i < fl_vertices.size(); i++)
        {
            out << "v " <<fl_vertices[i][0] << " " <<fl_vertices[i][1] << " "<<fl_vertices[i][2] <<"\r\n";
        }

        for(int i = 0; i < fl_lines.size(); i++)
        {
            out << "l " << fl_lines[i].p0 << " " << fl_lines[i].p1 <<"\r\n";
        }

        file->close();
    }
    else
    {
        return false;
    }

    if(file)
        delete file;

    return true;
}

bool FeatureLines::writeFacesToObj(const QString &fileName, const TriangleMesh *triMesh)
{
    if(!faces.size() || !triMesh)
        return false;

    vertices.clear();
    v_faces.clear();

    //将面片所在的顶点和三角形保存为obj格式
    int nv = triMesh->vertices.size();
    std::vector<int> iv;
    iv.resize(nv);

    for(int i = 0; i < faces.size(); i++)
    {
        iv[faces[i][0]] = 1;
        iv[faces[i][1]] = 1;
        iv[faces[i][2]] = 1;
    }

    for(int i = 0; i < iv.size(); i++)
    {
        if(iv[i] == 1)
        {
            iv[i] = vertices.size();
            vertices.push_back(triMesh->vertices[i]);
        }
    }

    for(int i = 0; i < faces.size(); i++)
    {
        //obj 文件中，表示三角形的 顶点下标从1开始。兼容geomagic
        v_faces.push_back(TriangleMesh::Face(iv[faces[i][0]]+1, iv[faces[i][1]]+1, iv[faces[i][2]]+1));
    }

    QFile *file = new QFile(fileName);

    if(file->open(QFile::WriteOnly))
    {
        QTextStream out(file);

        for(int i = 0; i < vertices.size(); i++)
        {
            out << "v " << vertices[i][0] << " " << vertices[i][1] << " " << vertices[i][2]<<"\r\n";
        }

        for(int i = 0; i < v_faces.size(); i++)
        {
            out << "f " << v_faces[i][0] << " " << v_faces[i][1] << " " << v_faces[i][2]<<"\r\n";
        }

        file->close();
    }
    else
    {
        return false;
    }

    if(file)
        delete file;

    return true;
}
