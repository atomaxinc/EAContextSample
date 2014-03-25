//
//  EAFlipsideViewController.m
//  EAContextSample
//
//  Created by Ryan on 13/11/26.
//  Copyright (c) 2013年 Atomax. All rights reserved.
//

#import "EAFlipsideViewController.h"
@interface EAFlipsideViewController ()

@end

@implementation EAFlipsideViewController

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    if (self.context.isConnected)
        [self.connectionToggleBtn setSelected:YES];
    else
        [self.connectionToggleBtn setSelected:NO];
    
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Actions

- (IBAction)done:(id)sender
{
    [self.delegate flipsideViewControllerDidFinish:self];
}

- (IBAction)didClickConnectBtn:(UIButton *)sender
{
    if (sender.isSelected)
    {
        [self.context disconnect];
        [sender setSelected:NO];
    }
    else
    {
        [self.context displayBluetoothLowEnergyPickerOnViewController:self WithCompletion:^(NSError *error) {
            
            if (error)
            {
                fprintf(stderr, "\n connect error -> %s",error.description.UTF8String);

            }
            
        }];
        
        [sender setSelected:YES];
    }
    
    
}



@end
