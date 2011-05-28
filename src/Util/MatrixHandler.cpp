#include "Util/MatrixHandler.hpp"

using namespace Util;

MatrixHandler *MatrixHandler::m_sInstance = NULL;

MatrixHandler::MatrixHandler()
{
}

MatrixHandler MatrixHandler::instance()
{
    if(m_sInstance == NULL)
        m_sInstance = new MatrixHandler();

    return (*m_sInstance);
}
