%Short one line introduction
% Longer multiline
% text explaining all features
%
% Usage:
% >> class(obj1, obj2); Explain...
% >> class(obj1); Explain...
%
% Parameters:
% obj1 explain.... [NUMERIC]
% obj2 explain.... [NUMERIC/PARAMETER]
%
% Example:
% >> an example...
%
% See also:
% acado.class.method1
% acado.class.method2
%
% Licence:
% This file is part of ACADO Toolkit  (http://www.acadotoolkit.org/)
%
% ACADO Toolkit, toolkit for Automatic Control and Dynamic Optimization.
% Copyright (C) 20082009 by Boris Houska and Hans Joachim Ferreau,
% K.U.Leuven. Developed within the Optimization in Engineering Center
% (OPTEC) under supervision of Moritz Diehl. All rights reserved.
%
% ACADO Toolkit is free software; you can redistribute it and/or
% modify it under the terms of the GNU Lesser General Public
% License as published by the Free Software Foundation; either
% version 3 of the License, or (at your option) any later version.
%
% ACADO Toolkit is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
% Lesser General Public License for more details.
%
% You should have received a copy of the GNU Lesser General Public
% License along with ACADO Toolkit; if not, write to the Free Software
% Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
% MA 021101301 USA
%
% Author: Rien Quirynen
% Date: 2012

classdef ExportModule < acado.UserInteraction
    properties (SetAccess='protected')
        name = 'ExportModule';
        
        % DifferentialEquation
        model;
        fileName;
        modelName;
        modelDiffsName;
        NX;
        NDX;
        NXA;
        NU;
        
        % dirName
        dir;
        run;
    end
    
    methods
        
        function obj = ExportModule(varargin)
            checkActiveModel;
            
            global ACADO_;
            ACADO_.helper.addModule(obj);
        end
        
        
        function s = toString(obj)
            s = obj.name;
        end
        
        
        function setModel(obj, varargin)
            
            global ACADO_;
            if (nargin == 2 && isa(varargin{1}, 'acado.DifferentialEquation'))
                % SIMexport.setModel( f );
                obj.model = varargin{1};
                
            elseif (nargin == 2 && (isa(varargin{1}, 'cell') || isa(varargin{1}, 'acado.Expression')))
                obj.model = acado.DifferentialEquation();
                ACADO_.helper.removeInstruction(obj.model);
                obj.model(:) = varargin{1};
                
            elseif (nargin == 4 && isa(varargin{1}, 'char') && isa(varargin{2}, 'char') && isa(varargin{3}, 'char'))
                % SIMexport.setModel( fileName, modelName, modelDiffsName );
                obj.fileName = varargin{1};
                obj.modelName = varargin{2};
                obj.modelDiffsName = varargin{3};
                
            else
                error('ERROR: Invalid setModel.');
                
            end
        end
        
        
        function setDimensions(obj, varargin)
            
            if (nargin == 3 && isa(varargin{1}, 'numeric') && isa(varargin{2}, 'numeric'))
                % SIMexport.setDimensions( NX, NU );
                obj.NX = varargin{1};
                obj.NDX = 0;
                obj.NXA = 0;
                obj.NU = varargin{2};
                
            elseif (nargin == 5 && isa(varargin{1}, 'numeric') && isa(varargin{2}, 'numeric') && isa(varargin{3}, 'numeric') && isa(varargin{4}, 'numeric'))
                % SIMexport.setDimensions( NX, NDX, NXA, NU );
                obj.NX = varargin{1};
                obj.NDX = varargin{2};
                obj.NXA = varargin{3};
                obj.NU = varargin{4};
                
            else
                error('ERROR: Invalid call to setDimensions.');
                
            end
            
        end
        
        
        function exportCode(obj, varargin)
            
            if (nargin == 2 && isa(varargin{1}, 'char'))
                % exportCode( dirName );
                obj.dir = varargin{1};
                obj.run = 0;
                
            elseif (nargin == 1)
                % exportCode( );
                obj.dir = './';
                obj.run = 0;
                
            else
                error('ERROR: Invalid exportCode. <a href="matlab: help acado.SIMexport.exportCode">help acado.SIMexport.exportCode</a>');
                
            end
            obj.setMEXFiles(obj.dir);
            obj.setMainFiles(obj.dir);
            
            GEN_ACADO; 
        end
        
        
        function setMEXFiles(obj, dir)
            if ~ischar(dir)
                error('Invalid directory name.');
            end
        end
        
        
        function setMainFiles(obj, dir)
            if ~ischar(dir)
                error('Invalid directory name.');
            end
        end
        
    end
    
end

