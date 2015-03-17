package LB01;

public class Numbers {

    private final int k;

    private final int[] data;

        public Numbers(int k)
        {
            this.k = 2;
            data = new int[k];
        }

        public Numbers(int[] data)
        {
            k = data.length;
            this.data = new int[k];
            this.data[0] = data[0];
            this.data[1] = data[1];
            this.data[2] = data[2];
        }

        private Numbers(Numbers A)
        { this(A.data);}

        public void show()
        {
            System.out.println(" " + data[0] + "+" + data[1] + "/" + data[2]);
        }

        public Numbers plus(Numbers Y)
        {
            Numbers X = this;
            int d = X.data.length;
            if (X.data[1] > X.data[2] || Y.data[1] > Y.data[2] )
                throw new RuntimeException("Illegal number");
            Numbers Z = new Numbers(d);
            Z.data[0] = X.data[0] + Y.data[0] + (X.data[1] * Y.data[2] + Y.data[1] * X.data[2]) / (X.data[2] * Y.data[2]);
            Z.data[1] = (X.data[1] * Y.data[2] + Y.data[1] * X.data[2]) % (X.data[2] * Y.data[2]);
            Z.data[2] = X.data[2] * Y.data[2];
            return Z;
        }

    public Numbers minus(Numbers Y)
    {
        Numbers X = this;
        int d = X.data.length;
        if (X.data[1] > X.data[2] || Y.data[1] > Y.data[2] )
            throw new RuntimeException("Illegal number");
        Numbers Z = new Numbers(d);
        Z.data[0] = X.data[0] - Y.data[0] + (X.data[1] * Y.data[2] - Y.data[1] * X.data[2]) / (X.data[2] * Y.data[2]);
        Z.data[1] = (X.data[1] * Y.data[2] - Y.data[1] * X.data[2]) % (X.data[2] * Y.data[2]);
        Z.data[2] = X.data[2] * Y.data[2];
        return Z;
    }

    public Numbers multiply(Numbers Y)
    {
        Numbers X = this;
        int d = X.data.length;
        if (X.data[1] > X.data[2] || Y.data[1] > Y.data[2] )
            throw new RuntimeException("Illegal number");
        Numbers Z = new Numbers(d);
        Z.data[0] = (X.data[0] * X.data[2] + X.data[1])*(Y.data[0] * Y.data[2] + Y.data[1]) / (X.data[2] * Y.data[2]);
        Z.data[1] = (X.data[0] * X.data[2] + X.data[1])*(Y.data[0] * Y.data[2] + Y.data[1]) % (X.data[2] * Y.data[2]);
        Z.data[2] = X.data[2] * Y.data[2];
        return Z;
    }

    public Numbers divide(Numbers Y)
    {
        Numbers X = this;
        int d = X.data.length;
        if (X.data[1] > X.data[2] || Y.data[1] > Y.data[2] )
            throw new RuntimeException("Illegal number");
        Numbers Z = new Numbers(d);
        Z.data[0] = ((X.data[0] * X.data[2] + X.data[1])*Y.data[2]) / (X.data[2] * (Y.data[0] * Y.data[2] + Y.data[1]));
        Z.data[1] = (X.data[0] * X.data[2] + X.data[1])*Y.data[2] % (X.data[2] * (Y.data[0] * Y.data[2] + Y.data[1]));
        Z.data[2] = X.data[2] * (Y.data[0] * Y.data[2] + Y.data[1]);
        return Z;
    }

    public Numbers prime()
    {
        Numbers X = this;
        int d = X.data.length;
        if (X.data[1] > X.data[2])
            throw new RuntimeException("Illegal number");
        Numbers Z = new Numbers(d);
        Z.data[0] = X.data[0];

        int s = X.data[1];
        for (int i = 2; i <= s; i++)
        {
            if((X.data[1]%i == 0)&&(X.data[2]%i == 0))
            {
                Z.data[1] = X.data[1]/i;
                Z.data[2] = X.data[2]/i;
            }

        }
        return Z;
    }

    public static void main(String[] args)

    {
        int[] d0 = {3777, 529, 731};
        Numbers A = new Numbers(d0);
        A.show();
        System.out.println();
        int[] d1 = {2123, 2102, 3991};
        Numbers B = new Numbers(d1);
        B.show();
        System.out.println();

        A.plus(B).show();
        System.out.println();

        A.minus(B).show();
        System.out.println();

        A.divide(B).show();
        System.out.println();

        Numbers C = A.multiply(B);
        C.show();
        System.out.println();

    }

}