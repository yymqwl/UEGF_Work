// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <soci/soci.h>


SOCI_API DECLARE_LOG_CATEGORY_EXTERN(Soci_Log,Log,All);


#define SOCI_LOG(Format, ...) \
UE_LOG(Soci_Log,Log,Format,##__VA_ARGS__)





#define SOCI_ERROR(Format, ...) \
UE_LOG(Soci_Log,Error,Format,##__VA_ARGS__)









class Ue_Soci_Log_Impl : public soci::logger_impl
{
public:
	virtual void start_query(std::string const& query) override;
private:
	virtual Ue_Soci_Log_Impl* do_clone() const override;
};

