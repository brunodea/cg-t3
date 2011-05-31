#include "Util/ModelViewMatrixStack.h"

using namespace Util;

ModelViewMatrixStack *ModelViewMatrixStack::m_sInstance = NULL;

ModelViewMatrixStack::ModelViewMatrixStack()
    : m_MatrixStack()
{
    m_pModelViewMatrix = new Core::Matrix4(0.f);
    loadIdentity();
}

ModelViewMatrixStack::~ModelViewMatrixStack()
{
}

ModelViewMatrixStack ModelViewMatrixStack::instance()
{
    if(m_sInstance == NULL)
        m_sInstance = new ModelViewMatrixStack();

    return (*m_sInstance);
}

void ModelViewMatrixStack::loadIdentity()
{
    Core::Matrix4 m = Core::identity<4>();
    *m_pModelViewMatrix = m;
}

void ModelViewMatrixStack::transform(Core::Matrix4 &mat)
{
    *m_pModelViewMatrix = (*m_pModelViewMatrix)*mat;
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
