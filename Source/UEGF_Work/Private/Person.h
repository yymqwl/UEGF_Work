#pragma once

#include "soci/soci.h"
//#include "soci/soci-backend.h"
#include "Soci/Private/SociSetting.h"
#include "CoreMinimal.h"
#include "Person.generated.h"

USTRUCT()
struct FPerson
{
	GENERATED_BODY();
public:
	//UPROPERTY()
	int Id;
	//UPROPERTY()
	FString Name;
};

struct Person
{
	int Id;
	std::string Name;
};
namespace soci
{
	template<>
	struct type_conversion<Person>
	{
		typedef values base_type;

		static void from_base(values const & v, indicator /* ind */, Person & p)
		{
			p.Id = v.get<int>("Id");
			p.Name = v.get<std::string>("Name");
		}

		static void to_base(const Person & p, values & v, indicator & ind)
		{
			v.set("Id", p.Id);
			v.set("Name", p.Name);
			ind = i_ok;
		}
	};
}