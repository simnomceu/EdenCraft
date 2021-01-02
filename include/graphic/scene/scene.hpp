/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															  .oooooo.                                  oooo         o8o            
															 d8P'  `Y8b                                 `888         `"'            
															888           oooo d8b  .oooo.   oo.ooooo.   888 .oo.   oooo   .ooooo.  
															888           `888""8P `P  )88b   888' `88b  888P"Y88b  `888  d88' `"Y8 
															888     ooooo  888      .oP"888   888   888  888   888   888  888       
															`88.    .88'   888     d8(  888   888   888  888   888   888  888   .o8 
															 `Y8bood8P'   d888b    `Y888""8o  888bod8P' o888o o888o o888o `Y8bod8P' 
																							  888                                   
																							 o888o                                  
                                                                       
                                          
                                     
				This file is part of EdenCraft Engine - Graphic module.
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

#ifndef SCENE_HPP
#define SCENE_HPP

#include "graphic/config.hpp"
#include "graphic/pch.hpp"
#include "graphic/scene/camera.hpp"
#include "graphic/renderable.hpp"
#include "graphic/scene/light.hpp"

namespace ece
{
	namespace graphic
	{
		namespace scene
		{
			/**
			 * @class Scene
			 * @brief
			 */
			class ECE_GRAPHIC_API Scene
			{
			public:
				/**
				 * @fn Scene() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				Scene() noexcept;

				/**
				 * @fn Scene(const Scene & copy)
				 * @param[in] copy The Scene to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				Scene(const Scene & copy) = default;

				/**
				 * @fn Scene(Scene && move) noexcept
				 * @param[in] move The Scene to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Scene(Scene && move) noexcept = default;

				/**
				 * @fn ~Scene() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Scene() noexcept = default;

				/**
				 * @fn Scene & operator=(const Scene & copy)
				 * @param[in] copy The Scene to copy from.
				 * @return The Scene copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Scene & operator=(const Scene & copy) = default;

				/**
				 * @fn Scene & operator=(Scene && move) noexcept
				 * @param[in] move The Scene to move from.
				 * @return The Scene moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Scene & operator=(Scene && move) noexcept = default;

				/**
				 * @fn Object * addObject()
				 * @return The new object created.
				 * @brief Add a new empty object to the scene.
				 * @throw
				 */
				auto addObject() -> Object::Reference;

				inline void addObject(const Renderable::Reference & object, int level = DEFAULT_LEVEL);

				inline void addLight(const Light::Reference & light);

				/**
				 * @fn Camera & getCamera()
				 * @return The camera of the scene.
				 * @brief Get the camera of the scene.
				 * @throw
				 */
				inline auto getCamera() -> Camera &;

				inline void updateCamera();

				auto getObjects() -> std::vector<Renderable::Reference>;
				auto getLights() -> std::vector<Light::Reference> &;

				void prepare();

				void sortObjects();

			private:
				struct CameraWrapper
				{
					Camera value;
					bool hasChanged;

					CameraWrapper(): value(), hasChanged() {}
					CameraWrapper(Camera valueIn, bool hasChangedIn): value(valueIn), hasChanged(hasChangedIn) {}
				};

				struct ObjectWrapper
				{
					Renderable::Reference value;
					bool hasChanged;
					int level;

					ObjectWrapper(const std::tuple< Renderable::Reference, bool, int> & rhs) : value(std::get<0>(rhs)), hasChanged(std::get<1>(rhs)), level(std::get<2>(rhs)) {}
					ObjectWrapper(std::tuple< Renderable::Reference, bool, int> && rhs) : value(std::get<0>(rhs)), hasChanged(std::get<1>(rhs)), level(std::get<2>(rhs)) {}

					ObjectWrapper & operator=(const std::tuple< Renderable::Reference, bool, int> & rhs)
					{
						this->value = std::get<0>(rhs);
						this->hasChanged = std::get<1>(rhs);
						this->level = std::get<2>(rhs);
					}
					ObjectWrapper & operator=(std::tuple< Renderable::Reference, bool, int> && rhs)
					{
						this->value = std::get<0>(rhs);
						this->hasChanged = std::get<1>(rhs);
						this->level = std::get<2>(rhs);
					}
				};

				class ObjectPack : public SoA<Renderable::Reference, bool, int>
				{
				public:
					std::vector<Renderable::Reference> & getRenderables() { return this->getAll(); }
					BooleanVector & hasChanged() { return this->SoA<bool, int>::getAll(); }
					std::vector<int> & getLevels() { return this->SoA<int>::getAll(); }
				};

				/**
				 * @property _camera
				 * @rief The camera of the scene.
				 */
				CameraWrapper _camera;

				/**
				 * @property _objects
				 * @brief The list of objects in the scene.
				 */
				ObjectPack _objects;

				std::vector<Light::Reference> _lights;

				static const int DEFAULT_LEVEL = 0;
			};
		} // namespace scene
	} // namespace graphic
} // namespace ece

#include "graphic/scene/scene.inl"

#endif // SCENE_HPP