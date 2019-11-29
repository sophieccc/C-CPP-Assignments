{\rtf1\ansi\ansicpg1252\cocoartf1671\cocoasubrtf600
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 void mainImage( out vec4 fragColor, in vec2 fragCoord )\
\{\
    vec2 uv = fragCoord;\
	vec3 linesColour = vec3(0.0, 0.0, 0.0);\
    vec3 pixel = vec3(1.0, 1.0, 1.0);\
\
    if(mod(uv.x,20.0)<1.0) pixel = linesColour;\
\
    // Output to screen\
    fragColor = vec4(pixel,1.0);\
\}}