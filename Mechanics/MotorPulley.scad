$fn = 72;

motorPulley();

translate([0, 0, 33])
motorPulleyMount();

module motorPulley()
{
    import("stl/motor_pulley.stl");
    
    translate([0, 0, 28])
    difference()
    {
        cylinder(d=11.8, h=8);
        cylinder(d=8.6, h=8+1);
    }
}

module motorPulleyMount()
{
    canDiam = 50.8;
    canRad = canDiam/2;
    mountOffset = 5;
    mountHeight = canRad + mountOffset;
    thickness=5;
    screwDiam=3.5;
    
    difference()
    {
        union()
        {
            cylinder(d=24.5+thickness*2, h=thickness*2, center=true);
            
            translate([-mountHeight/2, 0, 0])
            cube([mountHeight, 34.5, thickness*2], center=true);
            
            translate([-(mountHeight - thickness/2), 0, thickness*3])
            cube([thickness, thickness*8, thickness*8], center=true);
        }
        
        union()
        {
            cylinder(d=24.5, h=thickness*2+1, center=true);
            
            for (yOffset = [-thickness*2.5, thickness*2.5])
            {
                for (zOffset = [thickness*2.5, thickness*5.5])
                {
                    translate([0, yOffset, zOffset])
                    rotate([0, 90, 0])
                    cylinder(d=screwDiam, h=thickness*20, center=true);
                }
            }
        }
    }
}