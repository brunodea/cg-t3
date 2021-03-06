#ifndef _BRUNODEA_CG_T3_MATRIX_FUNCTIONS_HPP_
#define _BRUNODEA_CG_T3_MATRIX_FUNCTIONS_HPP_

/*
 * Funcoes auxiliares relacionado a matrizes a vetores.
 */

#include "Core/Matrix.hpp"
#include "Core/Vector.hpp"

#include <cmath>

namespace Core
{
    typedef Vector<float, 4> Vector4;
    typedef Vector<float, 3> Vector3;
    typedef Vector<float, 2> Vector2;
    
    typedef Matrix<float, 4> Matrix4;
    typedef Matrix<float, 3> Matrix3;
    typedef Matrix<float, 2> Matrix2;

    /* Retorna a matriz identidade de tamanho M. */
    template<unsigned int M>
    const Matrix<float, M> identity()
    {
        Matrix<float, M> res;
        for(unsigned int i = 0; i < M; i++)
        {
            for(unsigned int j = 0; j < M; j++)
            {
                if(i == j)
                    res.set(1.f, i, j);
                else
                    res.set(0.f, i, j);
            }
        }

        return res;
    }
    
    template<unsigned int M>
    float determinant(const Matrix<float, M, M> &mat)
    {
        float mul = 1;
        float sum = 0;
        for(unsigned int i = 0; i < M*M; i++)
        {
            if(i % M == 0 && i != 0)
            {
                sum += mul;
                mul = 1;
            }
            mul *= mat(i%M,((i%M) + i/M)%M);
        }
        mul = 1;
        for(unsigned int i = 0; i < M*M; i++)
        {
            if(i % M == 0 && i != 0)
            {
                sum -= mul;
                mul = 1;
            }
            mul *= mat(M-1-(i%M),((i%M) + i/M)%M);
        }

        return sum;
    }

    template<unsigned int M>
    Matrix<float, M, M> invert(const Matrix<float, M, M> &mat)
    {
        float det = determinant(mat);
        Core::Matrix<float, M, M> res = mat;
        if(det != 0)
        {
            res.print();
            res = Core::transpose(res);
            res.print();
            res *= ((float)1.f/det);
            res.print();
        }
        return res;
    }

    template<unsigned int M, unsigned int N>
    Matrix<float, N, M> transpose(const Matrix<float, M, N> &mat)
    {
        Matrix<float, N, M> res;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                res.set(mat(i,j), j, i);
        return res;
    }

    template<unsigned int M>
    Matrix<float, M> translate(const Vector<float, M> &vec)
    {
        Matrix<float, M> res = identity<M>();

        for(unsigned int i = 0; i < M-1; i++)
            res.set(vec(i, 0), i, M-1);

        return res;
    }

    inline Matrix4 translate3f(float x, float y, float z)
    {
        Vector4 vec(1.f);
        vec[0] = x;
        vec[1] = y;
        vec[2] = z;

        return translate(vec);
    }

    inline Matrix4 rotateX(float ang)
    {
        Matrix4 res = identity<4>();
        res.set(cos(ang), 1, 1);
        res.set(cos(ang), 2, 2);

        res.set(sin(ang), 2, 1);
        res.set(-sin(ang), 1, 2);

        return res;
    }

    inline Matrix4 rotateY(float ang)
    {
        Matrix4 res = identity<4>();
        res.set(cos(ang), 0, 0);
        res.set(cos(ang), 2, 2);

        res.set(sin(ang), 0, 2);
        res.set(-sin(ang), 2, 0);

        return res;
    }

    inline Matrix4 rotateZ(float ang)
    {
        Matrix4 res = identity<4>();
        res.set(cos(ang), 0, 0);
        res.set(cos(ang), 1, 1);

        res.set(sin(ang), 1, 0);
        res.set(-sin(ang), 0, 1);

        return res;
    }

    template<unsigned int M>
    inline Matrix<float, M> scale(const Vector<float, M> &vec)
    {
        Matrix<float, M> res = identity<M>();
        for(unsigned int i = 0; i < M-1; i++)
            res.set(vec(i,0),i,i);

        return res;
    }

    inline Matrix4 scale3f(float sx, float sy, float sz)
    {
        Vector4 vec(1.f);
        vec[0] = sx;
        vec[1] = sy;
        vec[2] = sz;

        return scale(vec);
    }

    template<unsigned int M>
    const float norm(const Vector<float, M> &vec)
    {
        float sum = 0.f;
        for(unsigned int i = 0; i < M; i++)
            sum += (vec(i,0)*vec(i,0));
        return sqrt((float)sum);
    }

    template<unsigned int M>
    const Core::Vector<float, M>normalize(const Vector<float, M> &vec)
    {
        Core::Vector<float, M> res;
        float n = norm(vec);
        for(unsigned int i = 0; i < M; i++)
            res.set(vec(i,0)/n, i, 0);
        return res;
    }

    //template<unsigned int M>
    //bool isUnitary(const Vector<float, M> &vec)
    //{
    //    return norm(vec) >= .5f || norm(vec) <= 1.5f; //com margem de erro .5 pra mais ou pra menos.
    //}

    template<unsigned int M>
    const float angle(const Vector<float, M> &v1, const Vector<float, M> &v2)
    {
        Vector<float, M> v1_unit = normalize(v1);
        Vector<float, M> v2_unit = normalize(v2);

        float ang = acos(v1_unit.dotProduct(v2_unit));
        return ang;
    }

    template<unsigned int M>
    const Matrix<float, M, 1> toMatrix(const Vector<float, M> &vec)
    {
        Matrix<float, M, 1> res;
        for(unsigned int i = 0; i < M; i++)
            res.set(vec[i], i, 0);

        return res;
    }

    template<unsigned int M>
    const Vector<float, M> toVector(const Matrix<float, M, 1> &mat)
    {
        Vector<float, M> res;
        for(unsigned int i = 0; i < M; i++)
            res[i] = mat(i, 0);
        return res;
    }

    inline Vector3 vector3f(float x, float y, float z)
    {
        Vector<float, 3> res;
        res[0] = x;
        res[1] = y;
        res[2] = z;
        return res;
    }

    inline Vector4 vector4f(float x, float y, float z, float w)
    {
        Vector<float, 4> res;
        res[0] = x;
        res[1] = y;
        res[2] = z;
        res[3] = w;

        return res;
    }

    inline Vector4 toVector4f(const Vector3 &v)
    {
        return vector4f(v(0,0),v(1,0),v(2,0),1);
    }

    inline Vector3 toVector3f(const Vector4 &v)
    {
        return vector3f(v(0,0),v(1,0),v(2,0));
    }

} //end of namespace Core.


#endif
