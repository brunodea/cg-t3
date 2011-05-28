#ifndef _BRUNODEA_CG_T3_MATRIX_HANDLER_HPP_
#define _BRUNODEA_CG_T3_MATRIX_HANDLER_HPP_

#include "Core/matrix_functions.hpp"

namespace Util
{
    class MatrixHandler
    {
    public:
        static MatrixHandler instance();

        void loadIdentity();
        void transform(Core::Matrix4 &mat);
        void translate(float x, float y, float z);
        void rotateX(float angle);
        void rotateY(float angle);
        void rotateZ(float angle);
        void scale(float sx, float sy, float sz);

        inline Core::Matrix4 getModelViewMatrix() { return m_ModelViewMatrix; }

    private:
        MatrixHandler();

    private:
        static MatrixHandler *m_sInstance;

        Core::Matrix4 m_ModelViewMatrix;

    }; //end of class MatrixHandler.
} //end of namespace Util.


#endif
