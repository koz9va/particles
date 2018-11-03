#include <iostream>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "curand.h"
#include <stdio.h>
#include "math.h"

const int am = 10;
const int threadsPerBlock = 256;
const int blocksPerGrid = (am + threadsPerBlock - 1) / threadsPerBlock;
double* particles = new double[am * 5];

// 0 x; 1 y; 2 z; 3 ang0; 4 ang1;

__global__ void process(double* parts, double* result)
{
	int inx = threadIdx.x + blockIdx.x * blockDim.x;
	double sin0;
	result[inx] = parts[inx] + sin(parts[inx+3])*cos(parts[inx+4]);
	
	__syncthreads();

}

int main()
{

	for (int i = 0; i < am; i++) {
		for (int x = 0; x < 5; x++) {
			particles[i + x] = 1;
		}
	}

	double* devparticles;
	double* devres;

	cudaMalloc((void**)&devparticles, sizeof(double)*am);
	cudaMalloc((void**)&devres, sizeof(double)*am);

	cudaMemcpy(devparticles, particles, sizeof(double) * am * 5, cudaMemcpyHostToDevice);

	process<<<blocksPerGrid,  threadsPerBlock>>>(devparticles, devres);

	cudaMemcpy(particles, devres, sizeof(double) * am * 5, cudaMemcpyDeviceToHost);



	cudaFree(devparticles);
	return 0;
}
