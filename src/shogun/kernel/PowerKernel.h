/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Soeren Sonnenburg, Evan Shelhamer, Björn Esser
 */

#include <shogun/lib/config.h>

#ifndef POWERKERNEL_H_
#define POWERKERNEL_H_

#include <shogun/lib/common.h>
#include <shogun/kernel/Kernel.h>
#include <shogun/distance/Distance.h>

namespace shogun
{

class CDistance;

/** @brief Power kernel
 *
 * Formally described as
 *
 * \f[
 *		K(x,x') = - \| x-x' \|^{degree}
 * \f]
 *
 */

class CPowerKernel: public CKernel
{
public:
	/** default constructor */
	CPowerKernel();

	/** constructor
	 * @param cache size of cache
	 * @param degree kernel parameter degree
	 * @param dist distance to be used
	 */
	CPowerKernel(int32_t cache, float64_t degree, CDistance* dist);

	/** constructor
	 * @param l features left-side
	 * @param r features right-side
	 * @param degree kernel parameter degree
	 * @param dist distance to be used
	 */
	CPowerKernel(CFeatures *l, CFeatures *r, float64_t degree, CDistance* dist);

	/** initialize kernel with features
	 * @param l features left-side
	 * @param r features right-side
	 * @return true if successful
	 */
	virtual bool init(CFeatures* l, CFeatures* r);

	/**
	 * @return kernel type
	 */
	virtual EKernelType get_kernel_type() { return K_POWER; }

	/**
	 * @return type of features
	 */
	virtual EFeatureType get_feature_type() { return distance->get_feature_type(); }

	/**
	 * @return class of features
	 */
	virtual EFeatureClass get_feature_class() { return distance->get_feature_class(); }

	/**
	 * @return name of kernel
	 */
	virtual const char* get_name() const { return "PowerKernel"; }

	virtual ~CPowerKernel();

protected:
	/**
	 * compute kernel for specific feature vectors
	 * corresponding to [idx_a] of left-side and [idx_b] of right-side
	 * @param idx_a left-side index
	 * @param idx_b right-side index
	 * @return kernel value
	 */
	virtual float64_t compute(int32_t idx_a, int32_t idx_b);

private:
	void init();

protected:

  /// distance to be used
	CDistance* distance;

	/// degree parameter of kernel
	float64_t m_degree;
};
}

#endif /* POWERKERNEL_H_ */
