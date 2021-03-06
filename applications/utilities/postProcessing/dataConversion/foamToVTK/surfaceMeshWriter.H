/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::surfaceMeshWriter

Description
    Write faces with fields

SourceFiles
    surfaceMeshWriter.C
    surfaceMeshWriterTemplates.C

\*---------------------------------------------------------------------------*/

#ifndef surfaceMeshWriter_H
#define surfaceMeshWriter_H

#include "pointMesh.H"
#include "OFstream.H"
#include "volFields.H"
#include "surfaceFields.H"
#include "vtkMesh.H"
#include "indirectPrimitivePatch.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class volPointInterpolation;

/*---------------------------------------------------------------------------*\
                           Class surfaceMeshWriter Declaration
\*---------------------------------------------------------------------------*/

class surfaceMeshWriter
{
    const vtkMesh& vMesh_;

    const bool binary_;

    const indirectPrimitivePatch& pp_;

    const fileName fName_;

    std::ofstream os_;

//    label nPoints_;
//
//    label nFaces_;

public:

    // Constructors

        //- Construct from components
        surfaceMeshWriter
        (
            const vtkMesh&,
            const bool binary,
            const indirectPrimitivePatch& pp,
            const word& name,
            const fileName&
        );


    // Member Functions

        std::ofstream& os()
        {
            return os_;
        }

//        label nPoints() const
//        {
//            return nPoints_;
//        }
//
//        label nFaces() const
//        {
//            return nFaces_;
//        }
//
//        //- Write cellIDs
//        void writePatchIDs();

        //- Extract face data
        template<class Type>
        tmp<Field<Type> > getFaceField
        (
            const GeometricField<Type, fvsPatchField, surfaceMesh>&
        ) const;

        //- Write surfaceFields
        template<class Type>
        void write
        (
            const PtrList<GeometricField<Type, fvsPatchField, surfaceMesh> >&
        );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include "surfaceMeshWriterTemplates.C"
#endif


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
