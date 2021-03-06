#ifndef _BRUNODEA_CG_T3_VECTOR_H_
#define _BRUNODEA_CG_T3_VECTOR_H_

/*
 * Classe vector lida com vetores. Eh apenas uma epecificacao da classe Matrix.
 */

#include "Core/Matrix.hpp"

namespace Core
{
    template<class T, unsigned int M>
    struct Vector : public Matrix<T, M, 1>
    {
        Vector() : Matrix<T, M, 1>() {}
        Vector(const Vector<T, M> &vec)
        {
            for(unsigned int i = 0; i < M; i++)
                set(vec(i,0), i, 0);
        }

        Vector(T val) : Matrix<T, M, 1>()
        {
            this->clear(val);
        }

        /* Produto Escalar. */
        inline float dotProduct(Vector<T, M> &vec)
        {
            float res = 0.f;
            for(unsigned int i = 0; i < M; i++)
                res += ((*this)(i, 0)*vec(i, 0));

            return res;
        }

        //Crossproduct generico.
        inline Vector<T, M> crossProduct(const Vector<T, M> &vec)
        {
            Vector<T, M> res;

            for(unsigned int i = 0; i < M; i++)
                res[(M-1+i)%M] = ((*this)(i,0)*vec((i+1)%M,0)) - ((*this)((i+1)%M,0)*vec(i,0));

            return res;
        }

        inline T &operator [](unsigned int i)
        {
            return (*this)(i, 0);
        }

        inline Vector<T, M> &operator =(Matrix<T, M, 1> &mat)
        {
            for(unsigned int i = 0; i < M; i++)
                set(mat(i, 0), i, 0);
            return (*this);
        }

        inline Vector<T, M> &operator =(const Matrix<T, M, 1> &mat)
        {
            for(unsigned int i = 0; i < M; i++)
                set(mat(i, 0), i, 0);
            return (*this);
        }

        inline Vector<T, M> &operator =(Vector<T, M> &vec)
        {
            for(unsigned int i = 0; i < M; i++)
                set(vec[i], i, 0);
            return (*this);
        }

    }; //end of struct Vector.
    
    template<class T, unsigned int M>
    inline Vector<T, M> operator -(const Vector<T, M> &v1, const Vector<T, M> &v2)
    {
        Vector<T, M> res = v1;
        res -= v2;

        return res;
    }
} //end of namespace Core.

#endif
