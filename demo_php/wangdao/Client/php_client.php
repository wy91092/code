/****************************************************
*
Author:yuandong
Date:2014-4-25
Description:用php写的udp客户端，该客户端只是一个媒介作用，目的是把
浏览器通过post请求传递的关键字通过udp协议传给server端(C语言写的),
因为浏览器不能直接把关键字发给server

*
*****************************************************/

<?php
$buff=$_REQUEST["content"];//采用$_REQUEST超全局数组来接收index.html页面post请求传递过来的数据

//udp  client 
$serverIp="127.0.0.1";//服务端ip地址，如果你的客户端与服务端不在同一台电脑，请修改该ip地址
$serverPort=5080;//通信端口号
//设置超时时间
set_time_limit(0);
//创建套接字
 $sock= socket_create(AF_INET, SOCK_DGRAM, SOL_UDP);
if(!$sock)
{
    echo "creat sock failed";
    exit();//创建套接字失败，结束程序
}
//发送数据到udp的服务端（C语言写的）
if(!socket_sendto($sock,$buff,strlen($buff),0,$serverIp,$serverPort))
{

	
    echo "send error\n";
    socket_close($sock);
    exit();

}

$buff="";//清空缓冲区
//接收udp server传递过来json字符串，存在变量$buff中
if(!socket_recvfrom($sock,$buff,10240,0,&$serverIp,&$serverPort))
{
         echo "recvieve error!";
         socket_close($sock);
         exit();
}

echo trim($buff)."\n";//去掉接受到的字符串的首尾空格，返回给post请求的data
//关闭套接字
socket_close($sock);
?>

