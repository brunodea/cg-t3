#include "Util/ModelViewMatrixStack.h"

using namespace Util;

ModelViewMatrixStack *ModelViewMatrixStack::m_sInstance = NULL;

ModelViewMatrixStack::ModelViewMatrixStack()
    : m_MatrixStack()
{
    m_MatrixStack.push(Core::identity<4>());
    m_Top = &m_MatrixStack.top();
}

ModelViewMatrixStack::~ModelViewMatrixStack()
{
}

ModelViewMatrixStack *ModelViewMatrixStack::instance()
{
    if(m_sInstance == NULL)
        m_sInstance = new ModelViewMatrixStack();

    return m_sInstance;
}

void ModelViewMatrixStack::loadIdentity()
{
    *m_Top = Core::identity<4>();
}

void ModelViewMatrixStack::transform(Core::Matrix4 &mat)
{
    m_Top = &m_MatrixStack.top();
    *m_Top = mat*(*m_Top);
}

void ModelViewMatrixStack::translate(float x, float y, float z)
{
    Core::Matrix4 m = Core::translate3f(x, y, z);
    transform(m);
}

void ModelViewMatrixStack::rotateX(float ang)
{
    Core::Matrix4 m = Core::rotateX(ang);
    transform(m);
}

void ModelViewMatrixStack::rotateY(float ang)
{
    Core::Matrix4 m = Core::rotateY(ang);
    transform(m);
}

void ModelViewMatrixStack::rotateZ(float ang)
{
    Core::Matrix4 m = Core::rotateZ(ang);
    transform(m);
}

void ModelViewMatrixStack::scale(float sx, float sy, float sz)
{
    Core::Matrix4 m = Core::scale3f(sx, sy, sz);
    transform(m);
}
