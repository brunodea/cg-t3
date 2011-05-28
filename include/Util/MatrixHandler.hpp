#ifndef _BRUNODEA_CG_T3_MATRIX_HANDLER_HPP_
#define _BRUNODEA_CG_T3_MATRIX_HANDLER_HPP_

#include "Core/matrix_functions.hpp"

#include <stack>

namespace Util
{
    class MatrixHandler
    {
    public:
        ~MatrixHandler();
        static MatrixHandler instance();

        void loadIdentity();
        void transform(Core::Matrix4 &mat);
        void translate(float x, float y, float z);
        void rotateX(float angle);
        void rotateY(float angle);
        void rotateZ(float angle);
        void scale(float sx, float sy, float sz);

        inline void pushMatrix() 
        { 
            m_MatrixStack.push(Core::Matrix4(*m_pModelViewMatrix));
        }
        inline void popMatrix() 
        { 
            m_MatrixStack.pop(); 
            if(!m_MatrixStack.empty())
            {                
                std::stack<Core::Matrix4>::reference m = m_MatrixStack.top();
                m_pModelViewMatrix = &m;
            }
            else
                loadIdentity();
        }

    private:
        MatrixHandler();

    private:
        static MatrixHandler *m_sInstance;

        Core::Matrix4 *m_pModelViewMatrix;

        std::stack<Core::Matrix4> m_MatrixStack;

    }; //end of class MatrixHandler.
} //end of namespace Util.


#endif
