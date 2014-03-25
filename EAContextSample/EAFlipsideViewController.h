//
//  EAFlipsideViewController.h
//  EAContextSample
//
//  Created by Ryan on 13/11/26.
//  Copyright (c) 2013年 Atomax. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EAContext.h"

@class EAFlipsideViewController;

@protocol EAFlipsideViewControllerDelegate
- (void)flipsideViewControllerDidFinish:(EAFlipsideViewController *)controller;
@end

@interface EAFlipsideViewController : UIViewController

@property (nonatomic, weak) EAContext *context;
@property (weak, nonatomic) id <EAFlipsideViewControllerDelegate> delegate;
@property (strong, nonatomic) IBOutlet UIButton *connectionToggleBtn;

- (IBAction)done:(id)sender;

@end
