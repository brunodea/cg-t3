#include "Util/MatrixHandler.hpp"

using namespace Util;

MatrixHandler *MatrixHandler::m_sInstance = NULL;

MatrixHandler::MatrixHandler()
    : m_MatrixStack()
{
    m_pModelViewMatrix = new Core::Matrix4(0.f);
    loadIdentity();
}

MatrixHandler::~MatrixHandler()
{
}

MatrixHandler MatrixHandler::instance()
{
    if(m_sInstance == NULL)
        m_sInstance = new MatrixHandler();

    return (*m_sInstance);
}

void MatrixHandler::loadIdentity()
{
    Core::Matrix4 m = Core::identity<4>();
    *m_pModelViewMatrix = m;
}

void MatrixHandler::transform(Core::Matrix4 &mat)
{
    *m_pModelViewMatrix = (*m_pModelViewMatrix)*mat;
}

void MatrixHandler::translate(float x, float y, float z)
{
    Core::Matrix4 m = Core::translate3f(x, y, z);
    transform(m);
}

void MatrixHandler::rotateX(float ang)
{
    Core::Matrix4 m = Core::rotateX(ang);
    transform(m);
}

void MatrixHandler::rotateY(float ang)
{
    Core::Matrix4 m = Core::rotateY(ang);
    transform(m);
}

void MatrixHandler::rotateZ(float ang)
{
    Core::Matrix4 m = Core::rotateZ(ang);
    transform(m);
}

void MatrixHandler::scale(float sx, float sy, float sz)
{
    Core::Matrix4 m = Core::scale3f(sx, sy, sz);
    transform(m);
}
