pseudo_code
```

RC4_Encryption(K)
{
	//Creation of initial state and key bytes
	for( i = 0 to 255)
	{
		S[i] = i 
		K[i] = Key[i mod keylength]) 
		
	}
	//Permuting state bytes based on values of key bytes
	j = 0 ;
	for(i = 0 to 255)
	{
		j = j+S[i] + K[i] mod 256
		swap(S[i],S[j])
	}
	//Continuously permuting state bytes generating keys and encrypting
	 i = 0 ; 
	 j = 0; 
	 while(more byte to encrpyte)
	 {
		 i = i +1 mod 256
		j = j+S[i] mod 256
		swap(S[i], S[j])
		k = S[S[i]+S[j]]mod 256

		input P;
		C = P ^ K
		output C


	 }
	 

}
```
