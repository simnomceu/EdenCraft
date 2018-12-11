/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef OBJ_FORMAT_HPP
#define OBJ_FORMAT_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/mathematics.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace wavefront
			{
				/**
				 * @class OBJFormat
				 * @brief
				 */
				class ECE_UTILITY_API OBJFormat
				{
				public:
					struct GeometryStatement
					{
						bool _rat;
						enum
						{
							BMATRIX,
							BEZIER,
							BSPLINE,
							CARDINAL,
							TAYLOR
						} _type;
					};

					struct BasicMatrix
					{
						enum
						{
							U,
							V
						} _type;
						std::vector<float> _mat;
					};

					using Point = IntVector3u;

					struct Line
					{
						struct
						{
							IntVector3u _v;
							IntVector3u _vt;
						} _a;
						struct
						{
							IntVector3u _v;
							IntVector3u _vt;
						}  _b;
					};

					struct Vertex
					{
						IntVector3u _v;
						IntVector3u _vt;
						IntVector3u _vn;
					};
					using Face = std::vector<Vertex>;

					struct Curve
					{
						FloatVector2u _u;
						std::vector<int> _v;
					};

					using Curve2D = std::vector<int>;

					struct Surface
					{
						FloatVector2u _s;
						FloatVector2u _t;
						std::vector<Vertex> _v;
					};

					struct TrimmingCurve
					{
						FloatVector2u _u;
						int _curv2D;
					};
					using TrimmingLoop = std::vector<TrimmingCurve>;

					struct Form
					{
						std::vector<GeometryStatement> _cstype; // forms of curve or surface type
						std::vector<IntVector2u> _deg; // degree
						std::vector<BasicMatrix> _bmat; // basis matrix
						std::vector<IntVector2u> _step; // step size

						// Free-form curve/surface body statement
						struct
						{
							enum
							{
								U,
								V
							} _type;
							std::vector<float> _value;
						} _parm; // parameter values

						std::vector<TrimmingLoop> _trim; // outer trimming loop
						std::vector<TrimmingLoop> _hole; // inner trimming loop
						std::vector<TrimmingLoop> _scrv; // special curve
						std::vector<int> _sp; // special point
					};

					struct Connectivity
					{
						struct
						{
							int _surf;
							FloatVector2u _q;
							int _curv2d;
						} a;
						struct
						{
							int _surf;
							FloatVector2u _q;
							int _curv2d;
						} b;
					};

					/**
					 * @fn OBJFormat() noexcept
					 * @brief Default constructor.
					 * @throw noexcept
					 */
					OBJFormat() noexcept = default;

					/**
					 * @fn OBJFormat(const OBJFormat & copy)
					 * @param[in] copy The OBJFormat to copy from.
					 * @brief Default copy constructor.
					 * @throw
					 */
					OBJFormat(const OBJFormat & copy) = default;

					/**
					 * @fn OBJFormat(OBJFormat && move) noexcept
					 * @param[in] move The OBJFormat to move.
					 * @brief Default move constructor.
					 * @throw noexcept
					 */
					OBJFormat(OBJFormat && move) noexcept = default;

					/**
					 * @fn ~OBJFormat() noexcept
					 * @brief Default destructor.
					 * @throw noexcept
					 */
					~OBJFormat() noexcept = default;

					/**
					 * @fn OBJFormat & operator=(const OBJFormat & copy)
					 * @param[in] copy The OBJFormat to copy from.
					 * @return The OBJFormat copied.
					 * @brief Default copy assignment operator.
					 * @throw
					 */
					OBJFormat & operator=(const OBJFormat & copy) = default;

					/**
					 * @fn OBJFormat & operator=(OBJFormat && move) noexcept
					 * @param[in] move The OBJFormat to move.
					 * @return The OBJFormat moved.
					 * @brief Default move assignment operator.
					 * @throw noexcept
					 */
					OBJFormat & operator=(OBJFormat && move) noexcept = default;

					inline void addVertex(const FloatVector4u & v);
					inline void addVertex(FloatVector4u && v);

					inline void addVertexTexture(const FloatVector3u & vt);
					inline void addVertexTexture(FloatVector3u && vt);

					inline void addVertexNormal(const FloatVector3u & vn);
					inline void addVertexNormal(FloatVector3u && vn);

					inline void addVertexSpaceParameter(const FloatVector3u & vp);
					inline void addVertexSpaceParameter(FloatVector3u && vp);

				private:
					// Vertex Data
					std::vector<FloatVector4u> _v; // geometric vertices
					std::vector<FloatVector3u> _vt; // texture vertices
					std::vector<FloatVector3u> _vn; // vertex normals
					std::vector<FloatVector3u> _vp; // parameter space vertices

					std::vector<std::vector<Form>> _forms;

					// Elements
					std::vector<IntVector3u> _p; // point
					std::vector<Line> _l; // line
					std::vector<Face> _f; // face
					std::vector<Curve> _curv; // curve
					std::vector<Curve2D> _curv2; // 2D curve
					std::vector<Surface> _surf; // surface

					// Connectivity between free-form surfaces
					std::vector<Connectivity> _con; // connect

					// Grouping
					std::vector<std::string> _g; // group name
					std::vector<int> _s; // smoothing group
					std::vector<int> _mg; // merging group
					std::string _o; // object name

					// Dispay/render attributes
					bool _bevel; // bevel interpolation
					bool _c_interp; // color interpolation
					bool _d_interp; // dissolve interpolation
					int _lod; // level of detail
					std::vector<std::string> _maplib;
					std::string _usemap;
					std::string _usemtl; // material name
					std::vector<std::string> _mtllib; // material library
					std::string _shadow_obj; // shadow casting
					std::string _trace_obj; // ray tracing
					struct
					{
						enum
						{
							CPARM,
							CSPACE,
							CURV
						} _type;
						union
						{
							float _cparm;
							int _cspace;
							struct
							{
								float _dist;
								float _angle;
							} _curv;
						} _value;
					} _ctech; // curve approximation technique
					struct
					{
						enum
						{
							CPARMA,
							CPARMB,
							CSPACE,
							CURV
						} _type;
						union
						{
							struct
							{
								float _ures;
								float _vres;
							} _cparma;
							float _cparmb;
							int _cspace;
							struct
							{
								float _dist;
								float _angle;
							} _curv;
						} _value;
					} _stech; // surface approximation technique
				};
			} // namespace wavefront
		} // namespace formats
	} // namespace utility
} // namespace ece

#include "utility/formats/wavefront/obj_format.inl"

#endif // OBJ_FORMAT_HPP