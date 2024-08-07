int main (){
    int a, b, c; // definition 1
    {
        int b, c, d; // definition 2
        //a (def 1), b, c, d; definition 2
        {
            int c, d, e; //definition 3
        //a (def 1), b (def 2), c, d, e; definition 3
        }
        //a (def 1) ,b, c, d; definition 2 this one I did it wrong
    }
    //a,b,c; definition 1
}