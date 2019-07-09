$fn=72;

rotate([0, 90, 0])
idlerPulley();

idlerMount();

module idlerPulley()
{
    wallHeight=4;
    diam=10;
    shaftDiam=3;
    beltWidth=16;
    
    translate([0, 0, -(wallHeight*2 + beltWidth)/2])
    difference()
    {
        union()
        {
            cylinder(d1=diam+wallHeight*2, d2=diam, h=wallHeight);
            
            translate([0, 0, wallHeight])
            cylinder(d=diam, h=beltWidth);
            
            translate([0, 0, wallHeight+beltWidth])
            cylinder(d1=diam, d2=diam+wallHeight*2, h=wallHeight);
        }
        
        cylinder(d=shaftDiam, h=(wallHeight*2 + beltWidth));
    }
}

module idlerMount()
{
    length=7.5;
    width=30;
    height=25.4*(7/8)+12.5;
    screwWidth=3.5;
    shaftDiam=2.5;
    shaftZOffset=7.5+12.5/2;
    shaftYOffset=7.5;
    
    for (xMirror = [-1, 1])
    {
        scale([xMirror, 1, 1])
        translate([-(width/2 + 13), -shaftYOffset, shaftZOffset])
        difference()
        {
            union()
            {
                cube([width, length, height], center=true);
                translate([0, shaftYOffset, length/2-height/2])
                cube([width, length, length], center=true);
            }
            
            union()
            {
                translate([0, 0, 12.5/2])
                for (spacerXOffset = [-width/4, width/4])
                {
                    for (spacerZOffset = [0, 7])
                    {
                        translate([spacerXOffset, 0, spacerZOffset])
                        union()
                        {
                            rotate([90, 0, 0])
                            cylinder(d=screwWidth, h=height, center=true);
                        }
                    }
                }
                
                translate([width/4, shaftYOffset, -shaftZOffset])
                rotate([0, 90, 0])
                cylinder(d=shaftDiam, h=width/2, center=true);
            }
        }
    }
}