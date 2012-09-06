/*
 *    This file is part of ACADO Toolkit.
 *
 *    ACADO Toolkit -- A Toolkit for Automatic Control and Dynamic Optimization.
 *    Copyright (C) 2008-2009 by Boris Houska and Hans Joachim Ferreau, K.U.Leuven.
 *    Developed within the Optimization in Engineering Center (OPTEC) under
 *    supervision of Moritz Diehl. All rights reserved.
 *
 *    ACADO Toolkit is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    ACADO Toolkit is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with ACADO Toolkit; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */



/**
*    \file src/symbolic_expression/vt_time.cpp
*    \author Boris Houska, Hans Joachim Ferreau
*    \date 2008
*/

#include <acado/symbolic_expression/vt_time.hpp>



BEGIN_NAMESPACE_ACADO



TIME::TIME()
     :Expression( 1, 1, VT_TIME, 0 ){ }


TIME::TIME( uint nRows_, uint nCols_, String name_ )
     :Expression( nRows_, nCols_, VT_TIME, (uint) 0, name_ ){ }


TIME::TIME( const TIME &arg )
     :Expression(arg){ }


TIME::~TIME(){ }


TIME& TIME::operator=( const TIME &arg ){

    if( this != &arg ){

        Expression::operator=(arg);

    }
    return *this;
}


Expression* TIME::clone() const{

    return new TIME(*this);
}


CLOSE_NAMESPACE_ACADO

// end of file.
