#include "Util/MatrixHandler.hpp"

using namespace Util;

MatrixHandler *MatrixHandler::m_sInstance = NULL;

MatrixHandler::MatrixHandler()
    : m_Matrix4(0.f)
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
    m_Matrix4 = Core::identity<4>();
}

void MatrixHandler::transform(Core::Matrix4 &mat)
{
    m_Matrix4 = m_Matrix4*mat;
}
