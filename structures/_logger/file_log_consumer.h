#pragma once
#include "logger.h"
#include <fstream>
#include "../../gui/main_form.h"

namespace structures
{
    class FileLogConsumer :
        public structures::ILogConsumer
    {
    public:
        FileLogConsumer(const std::string& path);//cesta k suboru
        void logMessage(structures::LogType type, const std::string& message) override;
        void logDuration(size_t size, tests::DurationType duration, const std::string& message) override;
    private:
        std::ofstream fileStream_;
    };
}



