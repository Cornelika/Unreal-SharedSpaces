// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REQUESTS_USER_H
#define OVR_REQUESTS_USER_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_AbuseReportOptions.h"
#include "OVR_BlockedUserArray.h"
#include "OVR_UserAndRoomArray.h"
#include "OVR_UserArray.h"
#include "OVR_UserCapabilityArray.h"
#include "OVR_UserOptions.h"

/// \file
/// Overview:
/// User objects represent people in the real world; their hopes, their dreams, and their current presence information.
///
/// Verifying Identify:
/// You can pass the result of ovr_UserProof_Generate() and ovr_GetLoggedInUserID()
/// to your your backend. Your server can use our api to verify identity.
/// 'https://graph.oculus.com/user_nonce_validate?nonce=USER_PROOF&user_id=USER_ID&access_token=ACCESS_TOKEN'
///
/// NOTE: the nonce is only good for one check and then it's invalidated.
///
/// App-Scoped IDs:
/// To protect user privacy, users have a different ovrID across different applications. If you are caching them,
/// make sure that you're also restricting them per application.

/// Retrieve the user with the given ID. This might fail if the ID is invalid
/// or the user is blocked.
///
/// NOTE: Users will have a unique ID per application.
/// \param userID User ID retrieved with this application.
///
/// A message with type ::ovrMessage_User_Get will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUser().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_Get(ovrID userID);

/// Return an access token for this user, suitable for making REST calls
/// against graph.oculus.com.
///
/// A message with type ::ovrMessage_User_GetAccessToken will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type const char *.
/// Extract the payload from the message handle with ::ovr_Message_GetString().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetAccessToken();

/// Return the IDs of users entitled to use the current app that are blocked by
/// the specified user
///
/// A message with type ::ovrMessage_User_GetBlockedUsers will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrBlockedUserArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetBlockedUserArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetBlockedUsers();

/// Retrieve the currently signed in user. This call is available offline.
///
/// NOTE: This will not return the user's presence as it should always be
/// 'online' in your application.
///
/// NOTE: Users will have a unique ID per application.
///
/// <b>Error codes</b>
/// - \b 100: Something went wrong.
///
/// A message with type ::ovrMessage_User_GetLoggedInUser will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUser().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetLoggedInUser();

/// Retrieve a list of the logged in user's bidirectional followers.
///
/// A message with type ::ovrMessage_User_GetLoggedInUserFriends will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetLoggedInUserFriends();

/// DEPRECATED. Use ovr_User_GetLoggedInUserFriends() instead Will be removed
/// from headers at version v51.
///
/// Retrieve a list of the logged in user's bidirectional followers and any
/// rooms they might be in.
///
/// A message with type ::ovrMessage_User_GetLoggedInUserFriendsAndRooms will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserAndRoomArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserAndRoomArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetLoggedInUserFriendsAndRooms();

/// DEPRECATED. Will be removed from headers at version v51.
///
/// Returns a list of users that the logged in user was in a room with
/// recently, sorted by relevance, along with any rooms they might be in. All
/// you need to do to use this method is to use our Rooms API, and we will
/// track the number of times users are together, their most recent encounter,
/// and the amount of time they spend together.
///
/// Customization can be done via UserOptions. Create this object with
/// ovr_UserOptions_Create. The params that could be used are:
///
/// 1. ovr_UserOptions_SetTimeWindow - how recently should the users have
/// played? The default is ovrTimeWindow_ThirtyDays.
///
/// 2. ovr_UserOptions_SetMaxUsers - we will limit the number of results
/// returned. By default, the number is unlimited, but the server may choose to
/// limit results for performance reasons.
/// \param userOptions Additional configuration for this request. Optional.
///
/// A message with type ::ovrMessage_User_GetLoggedInUserRecentlyMetUsersAndRooms will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserAndRoomArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserAndRoomArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetLoggedInUserRecentlyMetUsersAndRooms(ovrUserOptionsHandle userOptions);

/// Get the next page of entries
///
/// A message with type ::ovrMessage_User_GetNextBlockedUserArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrBlockedUserArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetBlockedUserArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetNextBlockedUserArrayPage(ovrBlockedUserArrayHandle handle);

/// Get the next page of entries
///
/// A message with type ::ovrMessage_User_GetNextUserAndRoomArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserAndRoomArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserAndRoomArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetNextUserAndRoomArrayPage(ovrUserAndRoomArrayHandle handle);

/// Get the next page of entries
///
/// A message with type ::ovrMessage_User_GetNextUserArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetNextUserArrayPage(ovrUserArrayHandle handle);

/// Get the next page of entries
///
/// A message with type ::ovrMessage_User_GetNextUserCapabilityArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserCapabilityArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserCapabilityArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetNextUserCapabilityArrayPage(ovrUserCapabilityArrayHandle handle);

/// returns an ovrID which is unique per org. allows different apps within the
/// same org to identify the user.
/// \param userID to load the org scoped id of
///
/// A message with type ::ovrMessage_User_GetOrgScopedID will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrOrgScopedIDHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetOrgScopedID().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetOrgScopedID(ovrID userID);

/// Returns all accounts belonging to this user. Accounts are the Oculus user
/// and x-users that are linked to this user.
///
/// A message with type ::ovrMessage_User_GetSdkAccounts will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrSdkAccountArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetSdkAccountArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetSdkAccounts();

/// Part of the scheme to confirm the identity of a particular user in your
/// backend. You can pass the result of ovr_User_GetUserProof() and a user ID
/// from ovr_User_Get() to your your backend. Your server can then use our api
/// to verify identity. 'https://graph.oculus.com/user_nonce_validate?nonce=USE
/// R_PROOF&user_id=USER_ID&access_token=ACCESS_TOKEN'
///
/// NOTE: The nonce is only good for one check and then it is invalidated.
///
/// A message with type ::ovrMessage_User_GetUserProof will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserProofHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserProof().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetUserProof();

/// Launch the flow for blocking the given user. You can't follow, be followed,
/// invited, or searched by a blocked user, for example. You can remove the
/// block via ovr_User_LaunchUnblockFlow.
/// \param userID User ID of user being blocked
///
/// A message with type ::ovrMessage_User_LaunchBlockFlow will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLaunchBlockFlowResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLaunchBlockFlowResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_LaunchBlockFlow(ovrID userID);

/// Launch the flow for sending a follow request to a user.
/// \param userID User ID of user to send a follow request to
///
/// A message with type ::ovrMessage_User_LaunchFriendRequestFlow will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLaunchFriendRequestFlowResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLaunchFriendRequestFlowResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_LaunchFriendRequestFlow(ovrID userID);

/// Launch the flow for unblocking a user that the viewer has blocked.
/// \param userID User ID of user to unblock
///
/// A message with type ::ovrMessage_User_LaunchUnblockFlow will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLaunchUnblockFlowResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLaunchUnblockFlowResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_LaunchUnblockFlow(ovrID userID);

#endif
