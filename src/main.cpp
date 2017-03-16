
#include "jpg.h"
#include "mnist.h"



float dist(float* x, float* y){

    float S = 0;

	for(int i=0; i<784; i++) {
        
        S += (y[i]-x[i])*(y[i]-x[i]);
    }

    return S;
}

 

int main(int argc, char** argv)
{
    float** image = read_mnist("train-images.idx3-ubyte");
	float* labels = read_labels("train-labels.idx1-ubyte");	
	float** test_image = read_mnist("t10k-images.idx3-ubyte");
	

    for(int i=0; i<10000; i++) {	
		float mind = -1;
		int NN;

		for(int j=0; j<60000; j++) {
			float d = dist(test_image[i], image[j]);

			if (d<mind || mind == -1) {
				mind = d;
				NN=j;
			}

		}

		int inference = labels[NN]; 

        save_jpg(image[i], 28, 28, "%u/%04u.jpg", (int)labels[i], i);
    }
    return 0;
}
 


