#ifndef WindowModel_H
#define WindowModel_H

#include <memory>
#include <map>

namespace EnergyPlus {

	template < typename T >
	class EnumParser {
		std::map< std::string, T > m_Map;
	public:
		EnumParser() {
		};

		T StringToEnum( const std::string& value ) {
			auto iValue = m_Map.find( value );
			if ( iValue == m_Map.end() )
				throw std::runtime_error( "Incorrect enumerator assigned." );
			return iValue->second;
		}
	};

	namespace WindowManager {

		enum class WindowsModel { BuiltIn, External };

		// Class that reads IDF object and decides if interior or exterior window models
		// will be used.
		class CWindowModel {
		public:
			CWindowModel();

			static std::unique_ptr< CWindowModel > WindowModelFactory( std::string const & objectName );

			WindowsModel getWindowsModel() const;
			bool isExternalLibraryModel() const;

		private:
			WindowsModel m_Model;

		};

		enum class WindowsOpticalModel { Simplified, BSDF };

		class CWindowOpticalModel {
		public:
			CWindowOpticalModel();

			static std::unique_ptr< CWindowOpticalModel > WindowOpticalModelFactory();

			WindowsOpticalModel getWindowsOpticalModel() const;
			bool isSimplifiedModel() const;

		private:
			WindowsOpticalModel m_Model;
		};
	}

}

#endif