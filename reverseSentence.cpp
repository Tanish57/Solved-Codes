void reverse(string &str, int n){
  int st = 0, e = n-1;
  
  while(st<e){
    swap(str[st++], str[e--]);
  }
}

void reverseSentence(string &str, int n){
  reverse(str, str.length());
  
  int i = 0;
  while(str[i] != '\0'){
    int st = i;
    while(str[i] != ' ' && str[i] != '\0'){
      i++;
    }
    int e = i-1;
    while(st<e){
      swap(str[st++], str[e--]);
    }
    
    if(str[i] == ' '){
      i++;
    }
  }
}
