$fn = 72;

Tensioner2();

module Tensioner2()
{
    Roller();
    
    Holder();
}

module nut(height=12.5, radius=(8/16)*25.4/2-.7, fn=6)
{
   fudge = 1/cos(180/fn);
   cylinder(h=height,r=radius*fudge,$fn=fn);
}

module Holder()
{
    t= 5;
    axleDiam = 4.5;
    length = 50;
    height = 20;
    armOffset = -5;
    
    difference()
    {
        union()
        {
            for (xScale = [-1, 1])
            {
                scale([xScale, 1, 1])
                translate([length/2, 0, armOffset])
                cube([t*2, axleDiam+t*2, height], center=true);
            }
            
            translate([0, 0, -t/2 - height/2 + armOffset])
            cube([length+t*4, axleDiam+t*2, t], center=true);
        }
        
        union()
        {
            rotate([0, 90, 0])
            cylinder(d=axleDiam, h=length+10, center=true);
            
            
            for (xOffset = [-10, 10])
            {
                translate([xOffset, 0, 0])
                cylinder(d=(1/4*25.4), h=50, center=true);
                
                translate([xOffset, 0, -t/2 - height/2 + armOffset-12.5])
                nut();
            }
        }
    }
}

module Roller()
{
    t= 2.5;
    axleDiam = 5;
    outerDiam = 8.5;
    bearingDepth = 3.2;
    width = 25;
    depth = 20;
    screwDiam = 25.4/4 + .2;
    wallDiam = 18.4;
    
    rotate([0, 90, 0])
    translate([0, 0, -((wallDiam-(outerDiam+t))+ width)/2])
    difference()
    {
        union()
        {
            cylinder(d1=wallDiam, d2=outerDiam+t, h=(wallDiam-(outerDiam+t))/2);
            translate([0, 0, (wallDiam-(outerDiam+t))/2])
            cylinder(d=(outerDiam+t), h=width);
            translate([0, 0, (wallDiam-(outerDiam+t))/2 + width])
            cylinder(d1=(outerDiam+t), d2=wallDiam, h=(wallDiam-(outerDiam+t))/2);
        }
        
        union()
        {
            cylinder(d=axleDiam, h=50);
            cylinder(d=outerDiam, h=bearingDepth);
            translate([0, 0, (wallDiam-(outerDiam+t))+ width - bearingDepth])
            cylinder(d=outerDiam, h=bearingDepth);
        }
    }
}