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
 *    \file src/code_generation/export_data.cpp
 *    \author Hans Joachim Ferreau, Boris Houska
 *    \date 2010-2011
 */


#include <acado/code_generation/export_data.hpp>
#include <acado/code_generation/export_data_internal.hpp>

BEGIN_NAMESPACE_ACADO


//
// PUBLIC MEMBER FUNCTIONS:
//

ExportData::ExportData( )
{}

ExportData::~ExportData( )
{}

ExportDataInternal* ExportData::operator->()
{
	return (ExportDataInternal*)(SharedObject::operator->());
}

const ExportDataInternal* ExportData::operator->() const
{
	return (const ExportDataInternal*)(SharedObject::operator->());
}

returnValue	ExportData::setName(	const String& _name
									)
{
	return (*this)->setName( _name );
}


returnValue	ExportData::setType(	ExportType _type
									)
{
	return (*this)->setType( _type );
}

returnValue ExportData::setPrefix(	const String& _prefix
									)
{
	return (*this)->setPrefix( _prefix );
}

returnValue	ExportData::setDataStruct(	ExportStruct _dataStruct
										)
{
	return (*this)->setDataStruct( _dataStruct );
}

String ExportData::getName( ) const
{
	return (*this)->getName();
}

ExportType ExportData::getType( ) const
{
	return (*this)->getType();
}

String ExportData::getPrefix() const
{
	return (*this)->getPrefix();
}

String ExportData::getTypeString(	const String& _realString,
									const String& _intString
									) const
{
	return (*this)->getTypeString();
}


ExportStruct ExportData::getDataStruct( ) const
{
	return (*this)->getDataStruct();
}


String ExportData::getDataStructString( ) const
{
	return (*this)->getDataStructString();
}


String ExportData::getFullName( ) const
{
	return (*this)->getFullName();
}

returnValue ExportData::exportDataDeclaration(	FILE* file,
												const String& _realString,
												const String& _intString,
												int _precision
												) const
{
	return (*this)->exportDataDeclaration(file, _realString, _intString, _precision);
}

BooleanType ExportData::isGiven( )
{
	return (*this)->isGiven();
}

returnValue ExportData::setDoc(	const String& _doc
								)
{
	return (*this)->setDoc( _doc );
}

String ExportData::getDoc( ) const
{
	return (*this)->getDoc();
}

CLOSE_NAMESPACE_ACADO

// end of file.
