% Robot Model: 2-axis differential
% Eduardo Figueiredo Porto Filho
% Engenharia Elétrica - Universidade Federal de Campina Grande

%joy = vrjoystick(1);
MOV = [0 0 0];
eixoX = [1 0];
eixoY = [0 1];

while true
    
    x = axis(joy, 1);
    y = -axis(joy, 2);
    
    dir = [x y];
    
    cosAnguloX = dot(dir,eixoX)/(norm(dir)*norm(eixoX));
    anguloX = acos(cosAnguloX)*180/pi; %Graus
    
    cosAnguloY = dot(dir,eixoY)/(norm(dir)*norm(eixoY));
    anguloY = acos(cosAnguloY)*180/pi; %Graus
    
    vel = norm(dir)*100; %(x^2 + y^2)^(1/2)
    
    if vel > 100
        vel = 100;
    end
    
    %for i = 0; i <= 2; i++
     %MOV(1,i) = rem(vel,10);
        %vel = vel / 10;
    %end
    
    for i = 1:3
        MOV(1,i) = int64(rem(vel,10));
        vel = vel / 10;
    end
    
    if y >= 0 && anguloX >= 45 && anguloX <= 135
        AX = 1;
    elseif y < 0 && anguloX >= 45 && anguloX <= 135
        AX = -1;
    elseif x >= 0 && anguloY > 45 && anguloY < 135
        AX = 2;
    elseif x < 0 && anguloY > 45 && anguloY < 135
        AX = -2;
    else
        AX = 1;
    end
    
    for i = 1:3
        %fwrite (joy, MOV(1,i);
        MOV(1,i)
    end
    
    %fwrite (joy, AX);
    AX
    
    pause(1);
    
end