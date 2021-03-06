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
 *    \file examples/basic_data_structures/interval_tutorial.cpp
 *    \author Boris Houska
 *    \date 2013
 */

#include <acado/set_arithmetics/set_arithmetics.hpp>


/* >>> start tutorial code >>> */
int main( ){

	USING_NAMESPACE_ACADO
	
	Interval x(-0.1,0.1);
	Interval y( 1,2);
	
	Interval z = asin(x) + x/y;
	
	z.print();
	
// 	(x/y).print();
// 	(sin(x)*cos(y)).print();
// 	(sqrt(x)).print();
// 	(sqrt(y)).print();
// 	(x*y+y/x).print();
// 	(log(x)).print();
// 	(-log(y)).print();
	
	return 0;
}
/* <<< end tutorial code <<< */


