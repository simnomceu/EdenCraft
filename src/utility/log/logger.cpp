#include "log\logger.hpp"

#include <iostream>
#include <ctime>

namespace ece
{
	void Logger::logError(const std::string & data)
	{
		std::time_t result = std::time(nullptr);
		tm today;
		localtime_s(&today, &result);

		std::string day = std::to_string(today.tm_mday);
		std::string month = std::to_string(today.tm_mon + 1);
		std::string year = std::to_string(today.tm_year + 1900);
		std::string hour = std::to_string(today.tm_hour);
		std::string min = std::to_string(today.tm_min);
		std::string sec = std::to_string(today.tm_sec);

		if (day.size() == 1) {
			day = "0" + day;
		}
		if (month.size() == 1) {
			month = "0" + month;
		}
		if (hour.size() == 1) {
			hour = "0" + hour;
		}
		if (min.size() == 1) {
			min = "0" + min;
		}
		if (sec.size() == 1) {
			sec = "0" + sec;
		}

		this->target << "[" << day << "/" << month << "/" << year << " " << hour << ":" << min << ":" << sec << "][ERROR]" << data << std::endl;
	}

	void Logger::logWarning(const std::string & data)
	{
		std::time_t result = std::time(nullptr);
		tm today;
		localtime_s(&today, &result);

		std::string day = std::to_string(today.tm_mday);
		std::string month = std::to_string(today.tm_mon + 1);
		std::string year = std::to_string(today.tm_year + 1900);
		std::string hour = std::to_string(today.tm_hour);
		std::string min = std::to_string(today.tm_min);
		std::string sec = std::to_string(today.tm_sec);

		if (day.size() == 1) {
			day = "0" + day;
		}
		if (month.size() == 1) {
			month = "0" + month;
		}
		if (hour.size() == 1) {
			hour = "0" + hour;
		}
		if (min.size() == 1) {
			min = "0" + min;
		}
		if (sec.size() == 1) {
			sec = "0" + sec;
		}

		this->target << "[" << day << "/" << month << "/" << year << " " << hour << ":" << min << ":" << sec << "][WARNING]" << data << std::endl;
	}

	void Logger::logInfo(const std::string & data)
	{
		std::time_t result = std::time(nullptr);
		tm today;
		localtime_s(&today, &result);

		std::string day = std::to_string(today.tm_mday);
		std::string month = std::to_string(today.tm_mon + 1);
		std::string year = std::to_string(today.tm_year + 1900);
		std::string hour = std::to_string(today.tm_hour);
		std::string min = std::to_string(today.tm_min);
		std::string sec = std::to_string(today.tm_sec);

		if (day.size() == 1) {
			day = "0" + day;
		}
		if (month.size() == 1) {
			month = "0" + month;
		}
		if (hour.size() == 1) {
			hour = "0" + hour;
		}
		if (min.size() == 1) {
			min = "0" + min;
		}
		if (sec.size() == 1) {
			sec = "0" + sec;
		}

		this->target << "[" << day << "/" << month << "/" << year << " " << hour << ":" << min << ":" << sec << "][INFO]" << data << std::endl;
	}
}
