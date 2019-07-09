$fn = 72;

//rotate([0, -90, 0])
motorMount();

module motorMount()
{
    shaftDiam=8;
    boltSpacing=44;
    canDiam=53.2;
    canLength=15;
    thickness=5;
    screwDiam0=3.5;
    screwDiam1=4.4;
    
    difference()
    {
        union()
        {
            rotate([0, 90, 0])
            cylinder(d=canDiam+thickness*2, h=canLength+thickness);
            
            translate([(canLength*2+thickness)/2, 0, (canDiam+thickness)/2])
            difference()
            {
                cube([canLength*2+thickness, canDiam*1.5, thickness], center=true);
                
                union()
                {
                    for (xOffset = [-canDiam/5, canDiam/5])
                    {
                        for (yOffset = [-canDiam*.6, 0, canDiam*.6])
                        {
                            translate([xOffset, yOffset, 0])
                            cylinder(d=screwDiam0, h=thickness*2, center=true);
                        }
                    }
                }
            }
        }
        union()
        {
            translate([thickness, 0, 0])
            rotate([0, 90, 0])
            cylinder(d=canDiam, h=canLength);
            
            rotate([0, 90, 0])
            cylinder(d=shaftDiam+thickness*2, h=canLength);
            
            rotate([0, 90, 0])
            for (rotAngle = [45:90:360])
            {
                rotate([0, 0, rotAngle])
                translate([0, boltSpacing/2, 0])
                cylinder(d=screwDiam1, h=thickness*2);
            }
            
            translate([thickness + canLength/2, -canDiam/2, 0])
            cube([canLength, 20, 25], center=true);
        }
    }
}