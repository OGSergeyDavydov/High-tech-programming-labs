#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

class Layer
{   
    public:
        int input_n;
        int max_epoch = 5;
        double bias;
        vector<double> weights;
        static double sigmoid(double x);
        double derivative_sigmoid(double x);


        Layer(int input_n);
        void set_weight_bias(vector<double> weights, double bias);
        void print_weight_bias();
        double forward(vector<double> in_values);
        void weights_correction(vector<double> in_values);
        double bias_correction();
        void backpropagation(vector<double> in_values);
};

Layer::Layer(int input_n)
{
    this->input_n = input_n;
    this->bias = rand()/(RAND_MAX+1.0);

    for (int i = 0; i < this->input_n; i++)
        this->weights.push_back(rand()/(RAND_MAX+1.0));
}

void Layer::set_weight_bias(vector<double> weights, double bias)
{
    for (int i = 0; i < this->input_n; ++i)
        this->weights[i] = weights[i];
    
    this->bias = bias;
}

void Layer::print_weight_bias()
{   
    cout << "weights: [ ";
    for (double x: this->weights)
        cout << x << " ";
    cout << "]";
    cout << endl << "bias = " << this->bias << endl;
}

double Layer::forward(vector<double> in_values) 
{
    double x = 0;
    for (int i = 0; i < this->input_n; i++)
        x += in_values[i]*this->weights[i];
    x += this->bias;

    return x;
}

double Layer::sigmoid(double x)
{
    return 1/(1+exp(-x));
}

double Layer::derivative_sigmoid(double x)
{
    return this->sigmoid(x)*(1-this->sigmoid(x));
}

void Layer::weights_correction(vector<double> in_values)
{
        for (int i = 0; i < input_n; i++)
            this->weights[i] -= 0.01*in_values[i]*this->derivative_sigmoid(this->forward(in_values));
}

double Layer::bias_correction()
{
        this->bias += 0.01*this->derivative_sigmoid(this->bias);
}

void Layer::backpropagation(vector<double> in_values)
{

    double y, tmp;
    double y1 = 1e6;

    for (int k = 0; k < this->max_epoch; k++)
    {
        y = this->sigmoid(this->forward(in_values));
        this->weights_correction(in_values);
        this->bias_correction();
        tmp = abs(y - y1);
        cout << "k = "<< k << " y = " << y << endl;
        y1 = y;
        this->print_weight_bias();
    }
}

int main()
{   
    srand(time(NULL));
    Layer FullyConnectedLayer(3);
    vector<double> w = {0, 0, 0};
    vector<double> in = {1, 0, 1};

    FullyConnectedLayer.set_weight_bias(w, 0);
    FullyConnectedLayer.backpropagation(in);

    return 0;
}
