//
//  OTAnnotationToolbarView.h
//
//  Copyright © 2016 Tokbox, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, OTAnnotationEventSignal) {
    OTAnnotationEventSignalDoneButtonClicked = 0,
    OTAnnotationEventSignalFreeHandButtonClicked = 1,
    OTAnnotationEventSignalColorPickerButtonClicked = 2,
    OTAnnotationEventSignalDidPickAColor = 3,
    OTAnnotationEventSignalTextAnnotationButtonClicked = 4,
    OTAnnotationEventSignalScreenCaptureButtonClicked = 5,
    OTAnnotationEventSignalEraseButtonClicked = 6
};


@class OTAnnotationToolbarView;
@protocol OTAnnotationToolbarViewDataSource <NSObject>
- (UIView *)annotationToolbarViewForRootViewForScreenShot:(OTAnnotationToolbarView *)toolbarView;
@end

@protocol OTAnnotationToolbarViewDelegate <NSObject>
- (void)annotationToolbarView:(OTAnnotationToolbarView *)toolbarView didPressToolbarViewItemButtonAtIndexPath:(NSIndexPath *)indexPath;
@end

@protocol OTAnnotationEventNotificatorDelegate <NSObject>
- (void)newNotificationEvent:(OTAnnotationEventSignal)event;
@end


@interface OTAnnotationToolbarView : UIView

@property (weak, nonatomic) id<OTAnnotationToolbarViewDataSource> toolbarViewDataSource;

@property (weak, nonatomic) id<OTAnnotationToolbarViewDelegate> toolbarViewDelegate;

@property (weak, nonatomic) id<OTAnnotationEventNotificatorDelegate> annotationEventDelegate;

@end
