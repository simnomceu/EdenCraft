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

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <memory>

#include "graphic/renderable/renderable.hpp"

namespace ece
{
	class Mesh;
	class Skeleton;
	class Texture;
	class ShaderEffect;
	class Animation;

    class Object: public Renderable
    {
    public:
        inline Object();
        Object(const Object & copy) = default;
        Object(Object && move) = default;

        ~Object() = default;

        Object & operator=(const Object & copy) = default;
		Object & operator=(Object && move) = default;

		// NOTE: each element should be build externally from this class, and just "linked" to it when required.
		inline void setMesh(const std::shared_ptr<Mesh> & mesh);
		inline void setSkeleton(const std::shared_ptr<Skeleton> & skeleton);
		inline void setTexture(const std::shared_ptr<Texture> & texture);
		inline void setShaderEffect(const std::shared_ptr<ShaderEffect> & shaderEffect);
		inline void setAnimation(const std::shared_ptr<Animation> & animation);

		// NOTE: accessing one of the elements linked to this object should not modify the object itself
		// but it should also not forbidding modification on the elements.
		inline std::shared_ptr<Mesh> getMesh() const;
		inline std::shared_ptr<Skeleton> getSkeleton() const;
		inline std::shared_ptr<Texture> getTexture() const;
		inline std::shared_ptr<ShaderEffect> getShaderEffect() const;
		inline std::shared_ptr<Animation> getAnimation() const;

		inline virtual Vertex * getVertices() const override;
		virtual std::vector<BaseUniform *> getUniforms() const override;
		virtual std::vector<ShaderSource *> getShaderSources() const override;

    protected:
		std::shared_ptr<Mesh> _mesh;
		std::shared_ptr<Skeleton> _skeleton;
		std::shared_ptr<Texture> _texture;
		std::shared_ptr<ShaderEffect> _shaderEffect;
		std::shared_ptr<Animation> _animation;
    };
}

#include "graphic/model/object.inl"

#endif // OBJECT_HPP