        int num1=facts[a],num2=facts[b],num3=facts[a-b];
        cout<< (num1%mod *(binexp((num2*num3)%mod,mod-2)%mod))%mod<<'\n';
