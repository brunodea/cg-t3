/* ModelViewMatrixStack eh uma pilha de matrizes que eh utilizada no mesmo estilo do openGL. Elas vao sendo guardadas conforme vao sendo necessarias. */

#ifndef _BRUNODEA_CG_T3_MATRIX_HANDLER_HPP_
#define _BRUNODEA_CG_T3_MATRIX_HANDLER_HPP_

#include "Core/matrix_functions.hpp"

#include <stack>
#include <vector>

namespace Util
{
    class ModelViewMatrixStack
    {
    public:
        ~ModelViewMatrixStack();
        static ModelViewMatrixStack *instance();

        void loadIdentity();
        void transform(Core::Matrix4 &mat);
        void translate(float x, float y, float z);
        void rotateX(float angle);
        void rotateY(float angle);
        void rotateZ(float angle);
        void scale(float sx, float sy, float sz);

        inline void pushMatrix() 
        {
            m_MatrixStack.push(*m_Top);
        }
        inline void popMatrix() 
        {
            m_MatrixStack.pop();
            if(m_MatrixStack.empty())
            {
                Core::Matrix4 top = Core::identity<4>();
                m_MatrixStack.push(top);
                m_Top = &m_MatrixStack.top();
            }
            else
                m_Top = &m_MatrixStack.top();
        }

        Core::Matrix4 getTop() { return *m_Top; }

        //para debug.
        void printStack()
        {
            unsigned int size = m_MatrixStack.size();
            std::cout << "Stack Size: " << size << std::endl;
            for(unsigned int i = 0; i < size; i++)
            {
                m_MatrixStack.top().print();
                m_MatrixStack.pop();
            }
        }

    private:
        ModelViewMatrixStack();

    private:
        static ModelViewMatrixStack *m_sInstance;

        std::stack<Core::Matrix4, std::vector<Core::Matrix4>> m_MatrixStack;
        Core::Matrix4 *m_Top;

    }; //end of class ModelViewMatrixStack.
} //end of namespace Util.


#endif
