#ifndef CH_UTILS_COMMON_H
#define CH_UTILS_COMMON_H

namespace chrono {
namespace utils {


enum SystemType {
	SEQUENTIAL_DVI,
	SEQUENTIAL_DEM,
	PARALLEL_DVI,
	PARALLEL_DEM
};


// -------------------------------------------------------------------------------
// GetSystemType()
//
// This utility function infers the type of the specified ChSystem.
// -------------------------------------------------------------------------------
SystemType GetSystemType(ChSystem* system)
{
	if (dynamic_cast<ChSystemParallelDVI*>(system))
		return PARALLEL_DVI;

	if (dynamic_cast<ChSystemParallelDEM*>(system))
		return PARALLEL_DEM;
	
	if (dynamic_cast<ChSystemDEM*>(system))
		return SEQUENTIAL_DEM;

	return SEQUENTIAL_DVI;
}


} // end namespace utils
} // end namespace chrono


#endif