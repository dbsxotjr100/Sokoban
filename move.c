void move_map(char x){
if(x=='h'){
  for(j=0;j<N;j++)
  for(k=0;k<M;k++)
  if(mp[s][j][k]=='@'){ //캐릭터의 위치를 찾기 위해서 조건을 걸음
  if(mp[s][j][k-1]==' '&&ospot[s][j][k]!='O'){//캐릭터 왼쪽이 여백이고 캐릭터의 현재 위치가 박스저장소가 아니면 여백으로 캐릭터를 밀음
  mp[s][j][k]=' ';
  mp[s][j][k-1]='@';
  }
  else if(mp[s][j][k-1]=='$'&&mp[s][j][k-2]=='$'){//캐릭터 왼쪽에 박스가 있고 그 왼쪽에 또 박스가 있으면 박스가 밀리지 않음
  mp[s][j][k]='@';
  mp[s][j][k-1]='$';
  mp[s][j][k-2]='$';
}
  else if(ospot[s][j][k]!='O'&&mp[s][j][k-1]=='$'&&(mp[s][j][k-2]==' '||mp[s][j][k-2]=='O')){
    //캐릭터 왼쪽에 박스가 있고 그 왼쪽이 벽이 아니라면 캐릭터와 박스가 왼쪽으로 밀림
  mp[s][j][k]=' ';
  mp[s][j][k-1]='@';
  mp[s][j][k-2]='$';
  }
  else if(ospot[s][j][k]=='O'&&mp[s][j][k-1]=='$'&&mp[s][j][k-2]=='O'){
    //현재 캐릭터 위치가 박스 저장소고 그 왼쪽이 박스고 박스의 왼쪽이 박스 저장소라면
    mp[s][j][k]='O';//원래 위치에 박스
    mp[s][j][k-1]='@';//캐릭터 이동
    mp[s][j][k-2]='$';//박스 이동
  }
  else if(ospot[s][j][k]=='O'&&(mp[s][j][k-1]==' '||mp[s][j][k-1]=='O')){//지금 캐릭터의 위치가 박스를 넣어야 되는 위치이고 움직이는 곳이 여백이나
    //다른 박스를 넣어야 되는 위치면 움직이게 함
  mp[s][j][k]='O';
  mp[s][j][k-1]='@';
}
else if(ospot[s][j][k]=='O'&&mp[s][j][k-1]==' '){
  //박스 위치를 저장한 배열의 위치가 현재 캐릭터의 위치이고 그 왼쪽이 공백이면 캐릭터를 왼쪽으로 밀고 상자 위치도 출력해줌
 mp[s][j][k]='O';
 mp[s][j][k-1]='@';
 }
 else if(mp[s][j][k-1]=='O'){//캐릭터 위치 옆이 박스 저장소면
   mp[s][j][k]=' ';
   mp[s][j][k-1]='@';//캐릭터 이동
 }
 system("clear");
 print_map(s);
  }
    }
else if(x=='k'){//앞에서 움직이는 거랑 방향만 다르기 때문에 코드의 알고리즘 형태는 똑같음
  undo_save(s);
  for(j=0;j<N;j++)
    for(k=0;k<M;k++)
    if(mp[s][j][k]=='@'){
    if(mp[s][j-1][k]==' '&&ospot[s][j][k]!='O'){
    mp[s][j][k]=' ';
    mp[s][j-1][k]='@';
    }
    else if(mp[s][j-1][k]=='$'&&mp[s][j-2][k]=='$'){
    mp[s][j][k]='@';
    mp[s][j-1][k]='$';
    mp[s][j-2][k]='$';
    }
    else if(ospot[s][j][k]!='O'&&mp[s][j-1][k]=='$'&&(mp[s][j-2][k]==' '||mp[s][j-2][k]=='O')){
    mp[s][j][k]=' ';
    mp[s][j-1][k]='@';
    mp[s][j-2][k]='$';
    }
    else if(ospot[s][j][k]=='O'&&mp[s][j-1][k]=='$'&&mp[s][j-2][k]=='O'){
      mp[s][j][k]='O';
      mp[s][j-1][k]='@';
      mp[s][j-2][k]='$';
    }
    else if(ospot[s][j][k]=='O'&&(mp[s][j-1][k]==' '||mp[s][j-1][k]=='O')){
    mp[s][j][k]='O';
    mp[s][j-1][k]='@';
    }
    else if(ospot[s][j][k]=='O'&&mp[s][j-1][k]==' '){
     mp[s][j][k]='O';
     mp[s][j-1][k]='@';
     }
     else if(mp[s][j-1][k]=='O'){
       mp[s][j][k]=' ';
       mp[s][j-1][k]='@';
     }
    system("clear");
    print_map(s);
    }
  }

else if(x=='l'){//마찬가지로 똑같음
  undo_save(s);
  for(j=0;j<N;j++)
  for(k=0;k<M;k++)
  if(mp[s][j][k]=='@'){
  if(mp[s][j][k+1]==' '&&ospot[s][j][k]!='O'){
  mp[s][j][k]=' ';
  mp[s][j][k+1]='@';
  }
  else if(ospot[s][j][k]!='O'&&mp[s][j][k+1]=='$'&&(mp[s][j][k+2]==' '||mp[s][j][k+2]=='O')){
  mp[s][j][k]=' ';
  mp[s][j][k+1]='@';
  mp[s][j][k+2]='$';
  }
  else if(mp[s][j][k+1]=='$'&&mp[s][j][k+2]=='$'){
  mp[s][j][k]='@';
  mp[s][j][k+1]='$';
  mp[s][j][k+2]='$';
  }
  else if(ospot[s][j][k]=='O'&&mp[s][j][k+1]=='$'&&mp[s][j][k+2]=='O'){
    mp[s][j][k]='O';
    mp[s][j][k+1]='@';
    mp[s][j][k+2]='$';
  }
  else if(ospot[s][j][k]=='O'&&(mp[s][j][k+1]==' '||mp[s][j][k+1]=='O')){
  mp[s][j][k]='O';
  mp[s][j][k+1]='@';
  }
  else if(ospot[s][j][k]=='O'&&mp[s][j][k+1]==' '){
   mp[s][j][k]='O';
   mp[s][j][k+1]='@';
   }
   else if(mp[s][j][k+1]=='O'){
     mp[s][j][k]=' ';
     mp[s][j][k+1]='@';
   }
  system("clear");
  print_map(s);
  }
}
else if(x=='j'){//마찬가지임
  undo_save(s);
  for(j=0;j<N;j++)
    for(k=0;k<M;k++)
    if(mp[s][j][k]=='@'){
    if(mp[s][j+1][k]==' '&&ospot[s][j][k]!='O'){
    mp[s][j][k]=' ';
    mp[s][j+1][k]='@';
    }
    else if(mp[s][j+1][k]=='$'&&mp[s][j+2][k]=='$'){
    mp[s][j][k]='@';
    mp[s][j+1][k]='$';
    mp[s][j+2][k]='$';
    }
    else if(ospot[s][j][k]!='O'&&mp[s][j+1][k]=='$'&&(mp[s][j+2][k]==' '||mp[s][j+2][k]=='O')){
    mp[s][j][k]=' ';
    mp[s][j+1][k]='@';
    mp[s][j+2][k]='$';
    }
    else if(ospot[s][j][k]=='O'&&mp[s][j+1][k]=='$'&&mp[s][j+2][k]=='O'){
      mp[s][j][k]='O';
      mp[s][j+1][k]='@';
      mp[s][j+2][k]='$';
    }
    else if(ospot[s][j][k]=='O'&&(mp[s][j+1][k]==' '||mp[s][j+1][k]=='O')){
    mp[s][j][k]='O';
    mp[s][j+1][k]='@';
  }
  else if(ospot[s][j][k]=='O'&&mp[s][j+1][k]==' '){
   mp[s][j][k]='O';
   mp[s][j+1][k]='@';
   }
   else if(mp[s][j+1][k]=='O'){
     mp[s][j][k]=' ';
     mp[s][j+1][k]='@';
   }
  system("clear");
  print_map(s);
    }
}
}
