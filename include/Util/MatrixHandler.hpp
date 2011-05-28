#ifndef _BRUNODEA_CG_T3_MATRIX_HANDLER_HPP_
#define _BRUNODEA_CG_T3_MATRIX_HANDLER_HPP_

namespace Util
{
    class MatrixHandler
    {
    public:
        static MatrixHandler instance();

    private:
        MatrixHandler();

    private:
        static MatrixHandler *m_sInstance;

    }; //end of class MatrixHandler.
} //end of namespace Util.


#endif
