#include "structures\_logger\file_log_consumer.h"


namespace structures
{
	FileLogConsumer::FileLogConsumer(const std::string& path) :
		fileStream_(path)		//ak by sa nepodaril otvorit
	{
		if (!this->fileStream_.is_open()) {
			throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open file: " + path);
		}
	}

	void FileLogConsumer::logMessage(structures::LogType type, const std::string& message)
	{
		this->fileStream_ << logTypeToString(type) << ";" << message << std::endl;		//v csv subore ; odelene
		//do suboru sa zapise 1 riadok log ; message
	}

	void FileLogConsumer::logDuration(size_t size, structures::DurationType duration, const std::string& message)
	{
		//zaznacena informacia o logu duraion

		this->fileStream_ <<size << ";" << duration.count() << ";" << message << std::endl;

	}
	
}


