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

        inline Core::Matrix4 getMatrix() { return m_Matrix4; }

    private:
        MatrixHandler();

    private:
        static MatrixHandler *m_sInstance;

        Core::Matrix4 m_Matrix4;

    }; //end of class MatrixHandler.
} //end of namespace Util.


#endif
