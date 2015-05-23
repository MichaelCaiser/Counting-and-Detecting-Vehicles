/*
 * ConfiguracionEmpotrado.hpp
 *
 * Author: Alonso Loaiza Pereira
 * e-mail: hiyitsu@gmail.com
 * University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * Description: Clase simple contenedora, encargada de almacenar la informacion de la configuracion del empotrado
 * para el envio de informacion a traves del web service.
 */

#ifndef CONFIGURACIONEMPOTRADO_HPP_
#define CONFIGURACIONEMPOTRADO_HPP_

class ConfiguracionEmpotrado
{
	public:

		//Constructor y Destructor
		ConfiguracionEmpotrado(int rEmpotradoID, int rEstructuraID);
		virtual ~ConfiguracionEmpotrado();

		//Getters
		int getEmpotradoID();
		int getEstructuraID();

		//Setters
		void setEmpotradoID(int rEmpotradoID);
		void setEstructuraID(int rEstructuraID);

	private:

		//Atributos
		int mEmpotradoID;
		int mEstructuraID;
};

#endif /* CONFIGURACIONEMPOTRADO_HPP_ */
