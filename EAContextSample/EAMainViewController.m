//
//  EAMainViewController.m
//  EAConetextSample
//
//  Created by Ryan on 13/11/26.
//  Copyright (c) 2013年 Atomax. All rights reserved.
//

#import "EAMainViewController.h"
#import "EAContext.h"

@interface EAMainViewController () <EAContextDelegate>
@property (nonatomic, strong) EAContext *context;
@end

@implementation EAMainViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    self.context = [[EAContext alloc] initWithSport:EASportTypeRAWData/*|EASportTypeBadminton*/ andConnectionType:EAConnectionTypeBLE];

    self.context.delegate = self;
    
    double delayInSeconds = 2.0;
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC));
    dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
        
        [self.context displayBluetoothLowEnergyPickerOnViewController:self WithCompletion:^(NSError *error){
            
            if (error)
            {
                printf("\n error -> %s",error.description.UTF8String);
            }
            
        }];
        
    });
    
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Flipside View

- (void)flipsideViewControllerDidFinish:(EAFlipsideViewController *)controller
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:@"showAlternate"]) {
        
        EAFlipsideViewController *flipViewController = [segue destinationViewController];
        
        flipViewController.context = self.context;
        
        
        [[segue destinationViewController] setDelegate:self];
    }
}

#pragma mark - EAContextDelegate

- (void)context:(EAContext *)context didUpdateCalculatedResultWithUserInfo:(NSDictionary *)userinfo
{
    if ((context.sportType & EASportTypeRAWData) == EASportTypeRAWData)
    {
        AMXVector3 accel = {0};
        
        [userinfo[kEASportResultAccelerometer] getValue:&accel];
        
        AMXVector3 gyro = {0};
        
        [userinfo[kEASportResultGyro] getValue:&gyro];
        
        AMXVector3 gravity = {0};
        
        [userinfo[kEASportResultGravity] getValue:&gravity];

        AMXVector3 userAccel = {0};
        
        [userinfo[kEASportResultUserAcceleration] getValue:&userAccel];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            
            self.accelValueLb_x.text = [NSString stringWithFormat:@"%f",accel.x];
            self.accelValueLb_y.text = [NSString stringWithFormat:@"%f",accel.y];
            self.accelValueLb_z.text = [NSString stringWithFormat:@"%f",accel.z];
            
            self.gyroValueLb_x.text = [NSString stringWithFormat:@"%f",gyro.x];
            self.gyroValueLb_y.text = [NSString stringWithFormat:@"%f",gyro.y];
            self.gyroValueLb_z.text = [NSString stringWithFormat:@"%f",gyro.z];
            
            self.gravityValueLb_x.text = [NSString stringWithFormat:@"%f",gravity.x];
            self.gravityValueLb_y.text = [NSString stringWithFormat:@"%f",gravity.y];
            self.gravityValueLb_z.text = [NSString stringWithFormat:@"%f",gravity.z];
            
            self.uAccelValueLb_x.text = [NSString stringWithFormat:@"%f",userAccel.x];
            self.uAccelValueLb_y.text = [NSString stringWithFormat:@"%f",userAccel.y];
            self.uAccelValueLb_z.text = [NSString stringWithFormat:@"%f",userAccel.z];

        });
        
    }
}


- (void)context:(EAContext *)context didFailToAccessWithError:(NSError *)error
{
    printf("\n error in MainWindowViewcontroller -> %s",[[error description] UTF8String]);
}



@end
