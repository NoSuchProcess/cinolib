/*********************************************************************************
*  Copyright(C) 2016: Marco Livesu                                               *
*  All rights reserved.                                                          *
*                                                                                *
*  This file is part of CinoLib                                                  *
*                                                                                *
*  CinoLib is dual-licensed:                                                     *
*                                                                                *
*   - For non-commercial use you can redistribute it and/or modify it under the  *
*     terms of the GNU General Public License as published by the Free Software  *
*     Foundation; either version 3 of the License, or (at your option) any later *
*     version.                                                                   *
*                                                                                *
*   - If you wish to use it as part of a commercial software, a proper agreement *
*     with the Author(s) must be reached, based on a proper licensing contract.  *
*                                                                                *
*  This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE       *
*  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.     *
*                                                                                *
*  Author(s):                                                                    *
*                                                                                *
*     Marco Livesu (marco.livesu@gmail.com)                                      *
*     http://pers.ge.imati.cnr.it/livesu/                                        *
*                                                                                *
*     Italian National Research Council (CNR)                                    *
*     Institute for Applied Mathematics and Information Technologies (IMATI)     *
*     Via de Marini, 6                                                           *
*     16149 Genoa,                                                               *
*     Italy                                                                      *
**********************************************************************************/
#include <cinolib/vertex_mass.h>

namespace cinolib
{

template<class M, class V, class E, class P>
CINO_INLINE
Eigen::SparseMatrix<double> mass_matrix(const AbstractMesh<M,V,E,P> & m)
{
    typedef Eigen::Triplet<double> Entry;

    std::vector<Entry>  entries;
    for(uint vid=0; vid<m.num_verts(); ++vid)
    {
        entries.push_back(Entry(vid, vid, m.vert_mass(vid)));
    }

    Eigen::SparseMatrix<double> MM(m.num_verts(), m.num_verts());
    MM.setFromTriplets(entries.begin(), entries.end());

    return MM;
}


}

