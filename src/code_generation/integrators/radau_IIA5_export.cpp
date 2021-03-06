/*
 *    This file is part of ACADO Toolkit.
 *
 *    ACADO Toolkit -(double)-(double) A Toolkit for Automatic Control and Dynamic Optimization.
 *    Copyright (C) 2008-(double)2009 by Boris Houska and Hans Joachim Ferreau, K.U.Leuven.
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
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-(double)1301  USA
 *
 */



/**
 *    \file src/code_generation/radau_IIA5_export.cpp
 *    \author Rien Quirynen
 *    \date 2012
 */

#include <acado/code_generation/integrators/radau_IIA5_export.hpp>

#include <acado/code_generation/export_algorithm_factory.hpp>

BEGIN_NAMESPACE_ACADO


//
// PUBLIC MEMBER FUNCTIONS:
//

RadauIIA5Export::RadauIIA5Export(	UserInteraction* _userInteraction,
									const String& _commonHeaderName
									) : ImplicitRungeKuttaExport( _userInteraction,_commonHeaderName )
{
	numStages = 3;
}


RadauIIA5Export::RadauIIA5Export(	const RadauIIA5Export& arg
									) : ImplicitRungeKuttaExport( arg )
{
	numStages = 3;
	copy( arg );
}


RadauIIA5Export::~RadauIIA5Export( )
{
	clear( );
}


returnValue RadauIIA5Export::initializeButcherTableau() {
	AA = Matrix(3,3);
	bb = Vector(3);
	cc = Vector(3);
			
	AA(0,0) = -(double)(1/(double)360)*(double)sqrt((double)6)*(double)(-(double)4+(double)(double)sqrt((double)6))*(double)(67+(double)(double)37*(double)sqrt((double)6))/(double)(6+(double)(double)sqrt((double)6));
	AA(0,1) = (1/(double)720)*(double)(-(double)4+(double)(double)sqrt((double)6))*(double)(-(double)4+(double)(double)sqrt((double)6))*(double)sqrt((double)6)*(double)(26+(double)(double)sqrt((double)6))/(double)(-(double)6+(double)(double)sqrt((double)6));		
	AA(0,2) = (1/(double)450)*(double)(-(double)4+(double)(double)sqrt((double)6))*(double)(-(double)4+(double)(double)sqrt((double)6))*(double)(2+(double)(double)sqrt((double)6));	
	AA(1,0) = -(double)(1/(double)720)*(double)(4+(double)(double)sqrt((double)6))*(double)(4+(double)(double)sqrt((double)6))*(double)sqrt((double)6)*(double)(-(double)26+(double)(double)sqrt((double)6))/(double)(6+(double)(double)sqrt((double)6));			
	AA(1,1) = -(double)(1/(double)360)*(double)sqrt((double)6)*(double)(4+(double)(double)sqrt((double)6))*(double)(-(double)67+(double)(double)37*(double)sqrt((double)6))/(double)(-(double)6+(double)(double)sqrt((double)6));		
	AA(1,2) = -(double)(1/(double)450)*(double)(4+(double)(double)sqrt((double)6))*(double)(4+(double)(double)sqrt((double)6))*(double)(-(double)2+(double)(double)sqrt((double)6));
	AA(2,0) = (5/(double)36)*(double)sqrt((double)6)*(double)(2+(double)(double)3*(double)sqrt((double)6))/(double)(6+(double)(double)sqrt((double)6));	
	AA(2,1) = -(double)(5/(double)36)*(double)sqrt((double)6)*(double)(-(double)2+(double)(double)3*(double)sqrt((double)6))/(double)(-(double)6+(double)(double)sqrt((double)6));				
	AA(2,2) = 1/(double)9;	
			
	bb(0) = (5/(double)36)*(double)sqrt((double)6)*(double)(2+(double)(double)3*(double)sqrt((double)6))/(double)(6+(double)(double)sqrt((double)6));		
	bb(1) = -(double)(5/(double)36)*(double)sqrt((double)6)*(double)(-(double)2+(double)(double)3*(double)sqrt((double)6))/(double)(-(double)6+(double)(double)sqrt((double)6));					
	bb(2) = 1/(double)9;
	
	cc(0) = 2/(double)5-(double)(1/(double)10)*(double)sqrt((double)6);		
	cc(1) = 2/(double)5+(double)(double)(1/(double)10)*(double)sqrt((double)6);	
	cc(2) = 1;
	
	return SUCCESSFUL_RETURN;
}


// PROTECTED:

//
// Register the integrator
//

IntegratorExport* createRadauIIA5Export(	UserInteraction* _userInteraction,
											const String &_commonHeaderName)
{
	return new RadauIIA5Export(_userInteraction, _commonHeaderName);
}

RegisterRadauIIA5Export::RegisterRadauIIA5Export()
{
	IntegratorExportFactory::instance().registerAlgorithm(INT_IRK_RIIA5, createRadauIIA5Export);
}

CLOSE_NAMESPACE_ACADO

// end of file.
